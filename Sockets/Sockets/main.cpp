#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    TCPSocketPtr serverSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

    SOCKADDR_IN addr;
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    serverSocket->Bind(*inAddress);

    serverSocket->Listen(1);

    TCPSocketPtr sockPtr = serverSocket->Accept(*inAddress);

    while (true)
    {
        char sibuf[50],
            sobuf[50];

        int status = sockPtr->Receive(sibuf, strlen(sibuf) + 1);
        if (status < 0) 
        {
            sockPtr = serverSocket->Accept(*inAddress);
        }
        std::cout << "Output: " << sibuf << std::endl;
        strcat_s(sibuf, " echo");
        sockPtr->Send(sibuf , strlen(sibuf) + 1);
    }
}