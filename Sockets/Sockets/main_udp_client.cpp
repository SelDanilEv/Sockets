#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.1.113:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    UDPSocketPtr clientSocket = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);
    UDPSocketPtr clientSocket2 = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);

    while (true) {
        std::string status = "";
        std::cin >> status;
        if (status == "exit")break;
        int i = 1;
        while (++i != 10000) {
            char ibuf[50];
            std::string obuf;

            obuf = std::to_string(i);
            obuf += "\0";

            clientSocket->SendTo(obuf.c_str(), strlen(obuf.c_str()) + 1, *inAddress);
            clientSocket2->SendTo(obuf.c_str(), strlen(obuf.c_str()) + 1, *inAddress);
            //clientSocket->ReceiveFrom(ibuf, strlen(ibuf) + 1,*inAddress);
            //std::cout << std::endl << ibuf << std::endl;
        }
    }
    SocketUtil::CleanUp();
}