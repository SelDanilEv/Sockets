#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    TCPSocketPtr clientSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

    clientSocket->Connect(*inAddress);

    int i = 0;

    while (i != 5) {

        char obuf[50];
        char ibuf[50];

        _itoa_s(++i, obuf, 10);

        clientSocket->Send(obuf, strlen(obuf) + 1);
        clientSocket->Receive(ibuf, strlen(ibuf) + 1);
        std::cout << std::endl << ibuf << std::endl;
    }

    SocketUtil::CleanUp();
}