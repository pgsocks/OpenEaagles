
#ifndef __oe_instruments_LandingLight_H__
#define __oe_instruments_LandingLight_H__

#include "LandingGear.hpp"

namespace oe {
namespace base { class Identifier; }
namespace instruments {

//------------------------------------------------------------------------------
// Class: LandingLight
//
// Description: Generic landing gear lights, which use the same principle as
// the landing gear, only they don't show a transitional phase, just off
// or on.
//
// Public member functions:
//      setLightRadius() - sets the radius (inches) of the light
//------------------------------------------------------------------------------
class LandingLight : public LandingGear
{
    DECLARE_SUBCLASS(LandingLight,LandingGear)

public:
    LandingLight();

    double getLightRadius() const { return lRadius; }

    virtual bool setLightRadius(const double newLR);

    virtual void updateData(const double dt = 0.0) override;

    virtual void drawFunc() override;

protected:
    // slot functions
    bool setSlotLightRadius(const base::Number* const newLR);

private:
    double lRadius {};     // our light radius - 0 means don't use it
    double gearCurrent {}; // our gear current value
    SendData selSD;        // our selection
};

}
}

#endif
