
#ifndef __oe_base_IoHandler_H__
#define __oe_base_IoHandler_H__

#include "openeaagles/base/Component.hpp"

namespace oe {
namespace base {
class Frequency;
class IoData;
class Number;
class Thread;
class IoThread;

//------------------------------------------------------------------------------
// Class: IoHandler
//
// Description: Handles the flow of I/O data to and from the I/O devices.
//
//    The I/O data is buffered using application specific IoData classes
//    (see IoData.h) that are attached to the I/O handler using the 'ioData',
//    'inputData' or 'outputData' slots (see note #2 below).
//
//    This I/O handler class will contain (via the 'devices' slot) a number of
//    I/O device handles (see IoDevice.h) to interface with the physical I/O
//    devices (e.g., joysticks, linkage systems).  Typically these I/O device
//    handlers will contain a number of I/O adapters that control the flow of
//    data between a device handler and an I/O data buffer (see IoAdapter.h).
//
//    For an example, see the example 'testIo'.
//
//
// Notes:
//    1) Data received from the hardware and sent to the simulation
//       software is "input" data, and data received from the simulation
//       software and sent to the hardware is "output" data.
//
//    2) The 'ioData' slot sets both the input and output handler pointers
//       to one combined I/O data buffer; or you can set just an input or
//       output data buffer; or set separate input/output data buffers, using
//       the 'inputData' and 'outputData' slots.
//
//    3) As an option, use createDataThread() to create a thread that will
//       call the I/O process functions for the devices; in which case, the
//       inputDevices() and outputDevices() are overridden.  This thread will
//       terminate when a SHUTDOWN_EVENT is sent to this object.
//
//
// Factory name: IoHandler
// Slots:
//    ioData      <IoData>       ! Combined input/output data (default: none)
//    inputData   <IoData>       ! Individual input data (default: none)
//    outputData  <IoData>       ! Individual output data (default: none)
//    devices     <PairStream>   ! List of I/O device handlers (IoDevice objects) (default: none)
//    rate        <Frequency>    ! Optional thread's update rate (default: 50hz)
//    priority    <Number>       ! Optional thread's priority: lowest(0.0) to highest(1.0)  (default: 0.5 )
//
//------------------------------------------------------------------------------
class IoHandler : public Component
{
   DECLARE_SUBCLASS(IoHandler, Component)

public:
   IoHandler();

   // Updates all of the input device handlers
   // (inoperative if the optional thread is active)
   virtual void inputDevices(const double dt);

   // Updates all of the output device handlers
   // (inoperative if the optional thread is active)
   virtual void outputDevices(const double dt);

   IoData* getInputData();                // Input data buffer
   const IoData* getInputData() const;    // Input data buffer (const version)

   IoData* getOutputData();               // Output data buffer
   const IoData* getOutputData() const;   // Output data buffer (const version)

   // (Optional) Creates a thread to process the I/O devices; (this
   // overrides the inputDevices() and outputDevices() functions)
   void createDataThread();
   double getPriority() const;            // Thread priority (0 low to 1 high)
   double getRate() const;                // Thread rate (hz)

   virtual void reset() override;

protected:
   bool areNetworksEnabled() const        { return netInitialized; }
   virtual bool initNetworks();           // Initialize the networks (if any)
   virtual void clear();                  // Clear our data

   // Slot functions
   virtual bool setSlotIoData(IoData* const msg);
   virtual bool setSlotInputData(IoData* const msg);
   virtual bool setSlotOutputData(IoData* const msg);
   virtual bool setSlotDevices(PairStream* const list);
   virtual bool setSlotRate(const Frequency* const num);
   virtual bool setSlotPriority(const Number* const num);

   virtual bool shutdownNotification() override;

private:
   // Implementations of the I/O device functions
   virtual void inputDevicesImp(const double dt);
   virtual void outputDevicesImp(const double dt);
   friend class IoThread;

   // Data I/O handlers
   safe_ptr<IoData> inData;       // "input" data received from the hardware
   safe_ptr<IoData> outData;      // "output" data sent to the hardware
   safe_ptr<PairStream> devices;  // Device list

   bool netInitialized {};        // Networks (if any) are initialized
   bool netInitFailed {};         // Network init has failed

   double rate {50};              // Thread Rate (hz)
   double pri {0.5};              // Priority of the thread (0->lowest, 1->highest)
   safe_ptr<base::Thread> thread; // The thread
};

}
}

#endif
