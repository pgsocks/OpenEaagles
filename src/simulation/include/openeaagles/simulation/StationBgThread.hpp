
#ifndef __oe_simulation_StationBgThread_H__
#define __oe_simulation_StationBgThread_H__

#include "openeaagles/base/concurrent/PeriodicTask.hpp"

namespace oe {
namespace simulation {

// ---
// Background thread
// ---
class BgThread : public base::PeriodicTask
{
   DECLARE_SUBCLASS(BgThread, base::PeriodicTask)
   public: BgThread(base::Component* const parent, const double priority, const double rate);
   private: virtual unsigned long userFunc(const double dt) override;
};

}
}



#endif
