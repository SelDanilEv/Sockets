#include "stdint.h"
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <iostream>

#include "../Serialization/MemoryShared.h"

#include "memory"

#include "vector"
#include "string"


using std::vector;
using std::string;
using std::shared_ptr;

#include "SocketAddress.h"
#include "UDPSocket.h"
#include "TCPSocket.h"
#include "SocketUtil.h"
#include "IPAddressFactory.h"
#include "TCPServer.h"

#pragma comment(lib,"WS2_32")

