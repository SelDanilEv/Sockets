#include "Shared.h"

int main()
{
    SocketUtil::StaticInit();
    //TCPSocketPtr serverSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

    //SOCKADDR_IN addr;
    SocketAddressPtr servAddr = IPAddressFactory::CreateIPv4FromString("192.168.43.112:2000");

    SocketAddress* inAddress = new SocketAddress(servAddr->mSockAddr);

    //serverSocket->Bind(*inAddress);

    //serverSocket->Listen(1);

    //serverSocket->Accept(*inAddress);

    //char sibuf[50],
    //    sobuf[50] = "sever: hello";

/*    serverSocket->Receive(sibuf, sizeof(sibuf));
    std::cout << sibuf;
    serverSocket->Send(sobuf, sizeof(sobuf))*/;

    //client
    TCPSocketPtr clientSocket = SocketUtil::CreateTCPSocket(SocketAddressFamily::INET);

    clientSocket->Connect(*inAddress);

    int i = 0;

    while (i != 9) {

        char obuf[50];
        char ibuf[50];

        _itoa_s(++i, obuf, 10);

        clientSocket->Send(obuf, strlen(obuf) + 1);
        clientSocket->Receive(ibuf, strlen(ibuf) + 1);
        std::cout << std::endl << ibuf << std::endl;
    }

    SocketUtil::CleanUp();
}