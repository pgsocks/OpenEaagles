
#ifndef __oe_base_FlowRate_H__
#define __oe_base_FlowRate_H__

#include "openeaagles/base/Number.hpp"
#include "openeaagles/base/units/Volumes.hpp"
#include "openeaagles/base/units/Times.hpp"

namespace oe {
namespace base {
//------------------------------------------------------------------------------
// Classes: FlowRate
//
// Description:  Flow Rate as a component of volume and time.
// Factory name: FlowRate
// Slots:
//    volume     <Volume>   ! Volume (default: 1 ft^3)
//    flowTime   <Time>     ! Time (default: 1 second)
//
// set() -- sets our velocity from some other velocity
//     bool FlowRate::set(const double newFlowRate, Volume* newVolume, Time* newTime)
//
// setSlotVolume() -- sets our volume object.
//     bool FlowRate::setSlotVolume(Volume* newVol)
//
// setSlotTime() -- sets our time object.
//     bool FlowRate::setSlotTime(Time* newTime)
//
// set() -- sets our velocity from some other velocity
//     bool FlowRate::set(const double newFlowRate, Volume* newVolume, Time* newTime)
//
// convert() -- converts from one volume/time ratio to another
//     double FlowRate::convert(Volume* newVolume, Time* newTime)
//
// serialize() -- print the value of this object to the output stream sout.
//     std::ostream& FlowRate::serialize(std::ostream& sout, const int i, const bool slotsOnly) const
//
//------------------------------------------------------------------------------
class FlowRate : public Number
{
    DECLARE_SUBCLASS(FlowRate, Number)

public:
    FlowRate(double newFlowRate, Volume* volume, Time* time);
    FlowRate();

    // dynamic convert routine
    double convert(Volume* newVolume, Time* newTime);
    // get functions
    double getFlowRate()                 { return flowRate; };
    // set functions
    bool set(const double newFlowRate, Volume* newVolume, Time* newTime);
    // slot table functions
    bool setSlotVolume(Volume* newVol);
    bool setSlotTime(Time* newTime);

private:
    Volume* myVolume {};       // holds our distance type
    Time*   myTime {};         // holds our time type
    double  flowRate {1.0};    // holds our velocity
};

}
}

#endif
