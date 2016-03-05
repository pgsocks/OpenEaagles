//------------------------------------------------------------------------------
// Class: TickMarks
//------------------------------------------------------------------------------
#ifndef __oe_instruments_TickMarks_H__
#define __oe_instruments_TickMarks_H__

#include "openeaagles/instruments/gauges/AnalogGauge.h"

namespace oe {
namespace instruments {

//------------------------------------------------------------------------------
// Class: TickMarks
//
// Description: Uses tick marks in a linear fashion, either horizontally or
// vertically, and draws them accordingly.  This is very similar to dial
// tick marks, only it doesn't rotate and doesn't draw around the circle.
//------------------------------------------------------------------------------
class TickMarks : public AnalogGauge
{
    DECLARE_SUBCLASS(TickMarks,AnalogGauge)

public:
    TickMarks();

    virtual bool setTickMarkLength(const LCreal newLength);
    virtual bool setQuantity(const int newQ);
    virtual bool setGaugeLength(const LCreal newL);
    virtual bool setFlip(const bool x);
    virtual bool setTickGraphic(const graphics::Graphic* const newGraphic);

    LCreal getTickMarkLength() const { return lengthTM; }
    int  getQuantity() const         { return quantity; }

    void drawFunc() override;

protected:
    // slot functions
    bool setSlotTickMarkLength(const base::Number* const newLength);
    bool setSlotQuantity(const base::Number* const newQ);
    bool setSlotGaugeLength(const base::Number* const newL);
    bool setSlotFlip(const base::Number* const x);

private:
    LCreal lengthTM;       // tick mark length (if not a graphic)
    int    quantity;       // how many tick marks will we have?
    LCreal gaugeLength;    // length we are spanning our tick marks over
    bool   flip;           // our flip variable
    graphics::Graphic* myGraphic; // our graphic (if we choose to use one for a tick mark)
};

}  // end of Instruments namespace
}  // end of oe namespace

#endif
