#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    UDPSocketPtr clientSocket = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);

    int i = 0;

    while (++i != 1000) {
        char ibuf[50];

        char const *obuf = std::to_string(i).c_str();

        clientSocket->SendTo(obuf, strlen(obuf),*inAddress);
        clientSocket->ReceiveFrom(ibuf, strlen(ibuf) + 1,*inAddress);
        std::cout << std::endl << ibuf << std::endl;
    }

    SocketUtil::CleanUp();
}