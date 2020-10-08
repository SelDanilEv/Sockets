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

        //_itoa_s(i, sobuf, 10);

        sockPtr->Receive(sibuf, strlen(sibuf) + 1);
        std::cout << "Output: " << sibuf << std::endl;
        sockPtr->Send(sibuf, strlen(sibuf) + 1);

        int t = 0;
        std::cin >> t;
        if (t == 1)
        {
            sockPtr = serverSocket->Accept(*inAddress);
        }
    }


    ////client
    //TCPSocketPtr clientSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);
    //
    //clientSocket->Connect(*inAddress);

    //char obuf[50] = "Hello";;
    //char ibuf[50];

    //clientSocket->Send(obuf, sizeof(obuf));
    //clientSocket->Receive(ibuf, sizeof(ibuf));
    //std::cout << ibuf;

}