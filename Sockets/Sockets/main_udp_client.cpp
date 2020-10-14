#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    UDPSocketPtr clientSocket = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);

    int i = 1;

    while (++i != 10000) {
        char ibuf[50];
        std::string obuf;

        obuf = std::to_string(i);
        obuf += "\0";

        clientSocket->SendTo(obuf.c_str(), strlen(obuf.c_str())+1,*inAddress);
        //clientSocket->ReceiveFrom(ibuf, strlen(ibuf) + 1,*inAddress);
        //std::cout << std::endl << ibuf << std::endl;
    }

    SocketUtil::CleanUp();
}