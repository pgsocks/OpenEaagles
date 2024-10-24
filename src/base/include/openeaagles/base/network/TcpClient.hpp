
#ifndef __oe_base_TcpClient_H__
#define __oe_base_TcpClient_H__

#include "openeaagles/base/network/TcpHandler.hpp"

namespace oe {
namespace base {

//------------------------------------------------------------------------------
// Class: TcpClient
//
// Description: Client side of a single TCP/IP connection.
//
//
// Factory name: TcpClient
// Slots:
//      ipAddress  <String>    ! Destination host name or IP address "111.122.133.144"
//                             ! (default: found via local host name)
//
//
// Input File Example:
//
//        ( TcpClient
//             ipAddress: hostname    // Server host name
//             port: 2010             // Server port
//        )
//
// Note: initNetwork() will wait on a connection even if the 'noWaitFlag' is true.
//
//------------------------------------------------------------------------------
class TcpClient : public TcpHandler
{
    DECLARE_SUBCLASS(TcpClient, TcpHandler)

public:
    TcpClient();

    // Slot functions
    virtual bool setSlotIpAddress(const String* const msg);

    virtual bool initNetwork(const bool noWaitFlag) override;

protected:
    const char* getIpAddress()  { return ipAddr; }
    bool connectToServer();      // Connect to the server

    virtual bool init() override;

    virtual bool bindSocket() override;

private:
    char* ipAddr {};                // IP Address
};

}
}

#endif

