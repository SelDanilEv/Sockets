#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    TCPSocketPtr serverSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

    SOCKADDR_IN addr;
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("127.0.0.1:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    serverSocket->Bind(*inAddress);

    serverSocket->Listen(1);

    serverSocket->Accept(*inAddress);


    //TCPSocket::Bind()

}