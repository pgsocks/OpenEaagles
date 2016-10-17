//------------------------------------------------------------------------------
// Class: NetIO
// Description: Portions of class defined to support munition detonation PDUs
//------------------------------------------------------------------------------

#include "openeaagles/networks/dis/NetIO.hpp"
#include "openeaagles/networks/dis/Nib.hpp"
#include "openeaagles/networks/dis/pdu.hpp"

#include "openeaagles/simulation/AirVehicle.hpp"
#include "openeaagles/simulation/Player.hpp"
#include "openeaagles/simulation/Simulation.hpp"
#include "openeaagles/simulation/Weapon.hpp"
#include "openeaagles/base/Nav.hpp"
#include "openeaagles/base/NetHandler.hpp"
#include "openeaagles/base/Pair.hpp"
#include "openeaagles/base/PairStream.hpp"

namespace oe {

namespace dis {

//------------------------------------------------------------------------------
// processDetonationPDU() callback --
//------------------------------------------------------------------------------
void NetIO::processDetonationPDU(const DetonationPDU* const pdu)
{
   // Get the Firing Player's ID
   unsigned short fPlayerId = pdu->firingEntityID.ID;
   unsigned short fSiteId = pdu->firingEntityID.simulationID.siteIdentification;
   unsigned short fApplicationId = pdu->firingEntityID.simulationID.applicationIdentification;

   // Ignore our own PDUs
   if (fSiteId == getSiteID() && fApplicationId == getApplicationID()) return;

   // Get the Munition Player's ID
   unsigned short mPlayerId = pdu->munitionID.ID;
   unsigned short mSiteId = pdu->munitionID.simulationID.siteIdentification;
   unsigned short mApplicationId = pdu->munitionID.simulationID.applicationIdentification;

   // Get the Target Player's ID
   unsigned short tPlayerId = pdu->targetEntityID.ID;
   unsigned short tSiteId = pdu->targetEntityID.simulationID.siteIdentification;
   unsigned short tApplicationId = pdu->targetEntityID.simulationID.applicationIdentification;

   // ---
   // 1) Find the target player
   // ---
   simulation::Player* tPlayer = nullptr;
   if (tPlayerId != 0 && tSiteId != 0 && tApplicationId != 0) {
      simulation::Nib* tNib = findDisNib(tPlayerId, tSiteId, tApplicationId, OUTPUT_NIB);
      if (tNib != nullptr) {
         tPlayer = tNib->getPlayer();
      }
   }
   //std::cout << "Net kill(2) tPlayer = " << tPlayer << std::endl;

   // ---
   // 2) Find the firing player and munitions (networked) IPlayers
   // ---
   simulation::Player* fPlayer = nullptr;
   if (fPlayerId != 0 && fSiteId != 0 && fApplicationId != 0) {
      simulation::Nib* fNib = findDisNib(fPlayerId, fSiteId, fApplicationId, INPUT_NIB);
      if (fNib != nullptr) {
         fPlayer = fNib->getPlayer();
      }
      else {
         base::safe_ptr<base::PairStream> players( getSimulation()->getPlayers() );
         fPlayer = getSimulation()->findPlayer(fPlayerId);
      }
   }

   simulation::Nib* mNib = nullptr;
   if (mPlayerId != 0 && mSiteId != 0 && mApplicationId != 0) {
      mNib = findDisNib(mPlayerId, mSiteId, mApplicationId, INPUT_NIB);
   }

    //std::cout << "Net kill(3) fNib = " << fNib << ", mNib = " << mNib << std::endl;

   // ---
   // 3) Update the data of the munition's NIB and player
   // ---
   simulation::Weapon* mPlayer = nullptr;
   if (mNib != nullptr) {

      // ---
      // a) Set the munition's NIB to the location of the detonation
      // ---

      // Get the geocentric position, velocity and acceleration from the PDU
      osg::Vec3d geocPos;
      geocPos[base::Nav::IX] = pdu->location.X_coord;
      geocPos[base::Nav::IY] = pdu->location.Y_coord;
      geocPos[base::Nav::IZ] = pdu->location.Z_coord;

      osg::Vec3d geocVel;
      geocVel[base::Nav::IX] = pdu->velocity.component[0];
      geocVel[base::Nav::IY] = pdu->velocity.component[1];
      geocVel[base::Nav::IZ] = pdu->velocity.component[2];

      osg::Vec3d geocAcc(0,0,0);
      osg::Vec3d geocAngles(0,0,0);
      osg::Vec3d arates(0,0,0);

      // (re)initialize the dead reckoning function
      mNib->resetDeadReckoning(
         simulation::Nib::STATIC_DRM,
         geocPos,
         geocVel,
         geocAcc,
         geocAngles,
         arates);

      // Set the NIB's mode to DETONATED
      mNib->setMode(simulation::Player::DETONATED);

      // Find the munition player and set its mode, location and target position
      mPlayer = dynamic_cast<simulation::Weapon*>(mNib->getPlayer());
      if (mPlayer != nullptr) {

         // Munition's mode
         mPlayer->setMode(simulation::Player::DETONATED);

         // munition's position, velocity and acceleration at the time of the detonation
         mPlayer->setGeocPosition(geocPos);
         mPlayer->setGeocVelocity(geocVel);
         mPlayer->setGeocAcceleration(geocAcc);

         // detonation results
         mPlayer->setDetonationResults(simulation::Weapon::Detonation(pdu->detonationResult));

         // Munition's target player and the location of detonation relative to target
         mPlayer->setTargetPlayer(tPlayer,false);
         double x = pdu->locationInEntityCoordinates.component[0];
         double y = pdu->locationInEntityCoordinates.component[1];
         double z = pdu->locationInEntityCoordinates.component[2];
         osg::Vec3 loc(x,y,z);
         mPlayer->setDetonationLocation(loc);

         // Munition's launcher
         if (mPlayer->getLaunchVehicle() == nullptr && fPlayer != nullptr) {
            mPlayer->setLaunchVehicle(fPlayer);
         }
      }
   }

   // ---
   // 4) Check all local players for the effects of the detonation
   // ---
   if (mPlayer != nullptr) {
      mPlayer->checkDetonationEffect();
   }
}

}
}
