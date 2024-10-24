
#ifndef __oe_models_RacModel_H__
#define __oe_models_RacModel_H__

#include "openeaagles/models/dynamics/AerodynamicsModel.hpp"

namespace oe {
namespace base { class Angle; class Distance; class Number; }
namespace models {

//------------------------------------------------------------------------------
// Class: RacModel
//
// Description: Robot Aircraft (RAC) Air Vehicle Dynamics Model
//                -- Very simple dynamics model
//
// Factory name: RacModel
// Slots:
//    minSpeed       <Number>    ! Minimum Velocity        (kts)
//    speedMaxG      <Number>    ! Velocity we reach max G (kts)
//    maxg           <Number>    ! Max G's (at "speedMaxG" or above)
//    maxAccel       <Number>    ! Maximum Acceleration    (m/s/s)
//    cmdAltitude    <Distance>  ! Command Altitude
//    cmdHeading     <Angle>     ! Command Heading
//    cmdSpeed       <Number>    ! Command speed           (kts)
//------------------------------------------------------------------------------
class RacModel : public AerodynamicsModel
{
    DECLARE_SUBCLASS(RacModel, AerodynamicsModel)

public:
    RacModel();

    virtual double getGload() const override;                   // G's (+up, one at level)
    virtual double getMach() const override;                    // mach number
    virtual double getAngleOfAttack() const override;           // radians
    virtual double getSideSlip() const override;                // radians
    virtual double getFlightPath() const override;              // radians
    virtual double getCalibratedAirspeed() const override;      // Kts

    virtual bool isHeadingHoldOn() const override;
    virtual double getCommandedHeadingD() const override;
    virtual bool setHeadingHoldOn(const bool b) override;
    virtual bool setCommandedHeadingD(const double h, const double hDps = 0, const double maxBank = 0) override;
    virtual bool isVelocityHoldOn() const override;
    virtual double getCommandedVelocityKts() const override;
    virtual bool setVelocityHoldOn(const bool b) override;
    virtual bool setCommandedVelocityKts(const double v, const double vNps = 0) override;
    virtual bool isAltitudeHoldOn() const override;
    virtual double getCommandedAltitude() const override;
    virtual bool setAltitudeHoldOn(const bool b) override;
    virtual bool setCommandedAltitude(const double a, const double aMps = 0, const double maxPitch = 0) override;
    virtual void dynamics(const double dt) override;            // One pass model update; called from Player::dynamics()

    virtual void reset() override;

    // Slot methods
    virtual bool setSlotMinSpeed(const base::Number* const msg);
    virtual bool setSlotSpeedMaxG(const base::Number* const msg);
    virtual bool setSlotMaxG(const base::Number* const msg);
    virtual bool setSlotMaxAccel(const base::Number* const msg);
    virtual bool setSlotCmdAltitude(const base::Distance* const msg);
    virtual bool setSlotCmdHeading(const base::Angle* const msg);
    virtual bool setSlotCmdVelocity(const base::Number* const msg);

private:
    void updateRAC(const double dt);

    double vpMin {};               // Minimum Velocity              (m/s)
    double vpMaxG {250.0};         // Velocity for Max G's          (g's)
    double gMax {4.0};             // Max G's                       (g's)
    double maxAccel {10.0};        // Max longitudinal acceleration (m/s/s)
    double cmdAltitude {-9999.0};  // Commanded Altitude            (meters)
    double cmdHeading {-9999.0};   // Commanded Heading             (degs)
    double cmdVelocity {-9999.0};  // Commanded speed               (kts)
};

}
}

#endif
