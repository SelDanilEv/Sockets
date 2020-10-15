#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    UDPSocketPtr serverSocket = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);

    SOCKADDR_IN addr;
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    serverSocket->Bind(*inAddress);
    bool flag = true;
    int i = 0;
    while (true)
    {
        char sibuf[50],
            sobuf[50];


        int status = serverSocket->ReceiveFrom(sibuf, strlen(sibuf) + 1, *inAddress);
        if (flag)
        {
            Sleep(1000);
            flag = false;
        }
        if (status < 0)
        {
            std::cout << status << std::endl;
            i = 0;
        }
        std::cout << ++i << "Output: " << sibuf << std::endl;
        strcat_s(sibuf, " echo");
        serverSocket->SendTo(sibuf, strlen(sibuf) + 1, *inAddress);
    }
}