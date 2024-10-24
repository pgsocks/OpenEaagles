
#ifndef __oe_linearsystem_Limit_H__
#define __oe_linearsystem_Limit_H__

#include "openeaagles/linearsystem/LimitFunc.hpp"

namespace oe {
namespace linearsystem {

//------------------------------------------------------------------------------
// Class: Limit
//
// Description: Limits function: limits X to the upper and lower boundaries.
//
// Factory name: Limit
// Slots:
//    lower  <Number>   Lower boundary (default: -1) (must be less than the upper)
//    upper  <Number>   Upper boundary (default:  1) (must be greater than the lower)
//
//------------------------------------------------------------------------------
class Limit : public LimitFunc
{
   DECLARE_SUBCLASS(Limit, LimitFunc)

public:
   Limit();
   Limit(const double lower, const double upper);

   // Set slot functions
   virtual bool setSlotLowerLimit(const base::Number* const msg);
   virtual bool setSlotUpperLimit(const base::Number* const msg);
};

}
}

#endif
