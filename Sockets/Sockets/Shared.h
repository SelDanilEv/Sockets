#include "stdint.h"
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include <WinSock2.h>
#include "Ws2tcpip.h"
#include <iostream>

#include "memory"

#include "vector"
#include "string"


using std::vector;
using std::string;
using std::shared_ptr;

#include "SocketAddress.h"
#include "TCPSocket.h"
#include "SocketUtil.h"
#include "UDPSocket.h"

#pragma comment(lib,"WS2_32")