
#ifndef __oe_iodevice_IoData_H__
#define __oe_iodevice_IoData_H__

#include "openeaagles/base/io/IoData.hpp"

namespace oe {
namespace base { class Number; }
namespace iodevice {

//------------------------------------------------------------------------------
// Class:  IoData
//
// Description:  General purpose I/O data buffer; users can specify the number
//               channels for each I/O type.
//
// Note:
//    *** Channel numbers are all one(1) based.  For example, the range of
//    AI channels is from one to getNumAnalogInputChannels(). ***
//
// Factory name: IoData
// Slots:
//    numAI    <Number>   ! Number of analog inputs (AIs)
//    numAO    <Number>   ! Number of analog outputs (AOs)
//    numDI    <Number>   ! Number of discrete inputs (DIs)
//    numDO    <Number>   ! Number of discrete outputs (DOs)
//
//------------------------------------------------------------------------------
class IoData : public base::IoData
{
   DECLARE_SUBCLASS(IoData, base::IoData)

public:
   IoData();

   bool setNumAI(const unsigned int num);
   bool setNumAO(const unsigned int num);
   bool setNumDI(const unsigned int num);
   bool setNumDO(const unsigned int num);

   virtual unsigned int getNumAnalogInputChannels() const override;
   virtual unsigned int getNumAnalogOutputChannels() const override;
   virtual unsigned int getNumDiscreteInputChannels() const override;
   virtual unsigned int getNumDiscreteOutputChannels() const override;
   virtual bool getAnalogInput(const unsigned int channel, double* const value) const override;
   virtual bool getAnalogOutput(const unsigned int channel, double* const value) const override;
   virtual bool getDiscreteInput(const unsigned int channel, bool* const value) const override;
   virtual bool getDiscreteOutput(const unsigned int channel, bool* const value) const override;
   virtual bool setAnalogInput(const unsigned int channel, const double value) override;
   virtual bool setAnalogOutput(const unsigned int channel, const double value) override;
   virtual bool setDiscreteInput(const unsigned int channel, const bool value) override;
   virtual bool setDiscreteOutput(const unsigned int channel, const bool value) override;
   virtual void clear() override;

protected:
   bool setSlotNumAI(const base::Number* const msg);
   bool setSlotNumAO(const base::Number* const msg);
   bool setSlotNumDI(const base::Number* const msg);
   bool setSlotNumDO(const base::Number* const msg);

private:
   unsigned int numAI {};  // Number of AIs
   double*  aiTable {};    // AIs

   unsigned int numAO {};  // Number of AOs
   double*  aoTable {};    // AOs

   unsigned int numDI {};  // Number of DIs
   bool*    diTable {};    // DIs

   unsigned int numDO {};  // Number of DOs
   bool*    doTable {};    // DOs
};

}
}

#endif
