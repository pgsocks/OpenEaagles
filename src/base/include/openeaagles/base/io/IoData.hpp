
#ifndef __oe_base_IoData_H__
#define __oe_base_IoData_H__

#include "openeaagles/base/Object.hpp"

namespace oe {
namespace base {

//------------------------------------------------------------------------------
// Class: IoData
// Description: I/O data buffer
//
//    Common interface to I/O channels that are used to hold data coming from
//    and going to our I/O devices.  These I/O channels contain applications
//    specific I/O items that are independent of the actual I/O device channels.
//    Derived classes will handle the application specific details.
//
//    For a standard I/O data buffer, see "openeaagles/iodevice/IoData.h".
//
//    The main input and output data buffers are typically managed by an I/O
//    handler class (see IoHander.h).
//
// Notes:
//    1) Inputs from hardware are called Analog Inputs (AI) and Discrete Inputs (DI)
//
//    2) Outputs to hardware are called Analog Outputs (AO) and Discrete Outputs (DO)
//
//    3) Channel numbering is application dependent; some applications may start
//       numbering at one(1) and some may start at zero(0).
//
//    4) All functions return true if successful.
//
//
// Factory name: GenericIoData
//
//------------------------------------------------------------------------------
class IoData : public Object
{
   DECLARE_SUBCLASS(IoData, Object)

public:
   IoData();

   // ---
   // Input channels
   // ---
   virtual unsigned int getNumAnalogInputChannels() const;
   virtual unsigned int getNumDiscreteInputChannels() const;

   // Returns the value of the analog input 'channel' in 'value'
   virtual bool getAnalogInput(const unsigned int channel, double* const value) const;

   // Returns the state of the discrete input bit 'channel' in 'value'
   virtual bool getDiscreteInput(const unsigned int channel, bool* const value) const;

   // Sets an analog input 'channel' to 'value'.
   virtual bool setAnalogInput(const unsigned int channel, const double value);

   // Sets the discrete input 'channel' to 'value'.
   virtual bool setDiscreteInput(const unsigned int channel, const bool value);

   // Process the input channels, if needed (application specific).
   // Called by the IoHandler just after the input devices are processed.
   virtual bool processInputs();

   // ---
   // Output channels
   // ---

   virtual unsigned int getNumDiscreteOutputChannels() const;
   virtual unsigned int getNumAnalogOutputChannels() const;

   // Returns the value of the analog output 'channel' in 'value'
   virtual bool getAnalogOutput(const unsigned int channel, double* const value) const;

   // Returns the state of the output bit 'channel' in 'value'
   virtual bool getDiscreteOutput(const unsigned int channel, bool* const value) const;

   // Sets an analog output 'channel' to 'value'.
   virtual bool setAnalogOutput(const unsigned int channel, const double value);

   // Sets the discrete output 'channel' to 'value'.
   virtual bool setDiscreteOutput(const unsigned int channel, const bool value);

   // Process the output channels, if needed (application specific).
   // Called by the IoHandler just before the output devices are processed.
   virtual bool processOutputs();

   // ---
   // Support functions
   // ---

   // Initialize the network (if any)
   virtual bool initNetwork();

   // Clear data
   virtual void clear();
};

}
}

#endif
