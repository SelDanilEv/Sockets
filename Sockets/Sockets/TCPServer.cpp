#include "Shared.h"

TCPServer::TCPServer()
{
}

TCPServer::~TCPServer()
{
}

void TCPServer::DoTCPLoop()
{
    const int GOOD_SEGMENT_SIZE = 5000;

    TCPSocketPtr listenSocket = SocketUtil::CreateTCPSocket(INET);
    SocketAddress receivingAddres(INADDR_ANY, 48000);
    if (listenSocket->Bind(receivingAddres) != NO_ERROR)
    {
        return;
    }
    vector<TCPSocketPtr> readBlockSockets;
    readBlockSockets.push_back(listenSocket);
    vector<TCPSocketPtr> readableSockets;
    while (gIsGameRunning)
    {
        if (SocketUtil::Select(&readBlockSockets, &readableSockets,
            nullptr, nullptr,
            nullptr, nullptr))
        {
            // получен пакет — обойти сокеты...
            for (const TCPSocketPtr& socket : readableSockets)
            {
                if (socket == listenSocket)
                {
                    // это сокет, принимающий запросы на соединение,
                    // принять новое соединение
                    SocketAddress newClientAddress;
                    auto newSocket = listenSocket->Accept(newClientAddress);
                    readBlockSockets.push_back(newSocket);
                    ProcessNewClient(newSocket, newClientAddress);
                }
                else
                {
                    // это обычный сокет — обработать данные...
                    char segment[GOOD_SEGMENT_SIZE];
                    int dataReceived = socket->Receive(segment, GOOD_SEGMENT_SIZE);
                    if (dataReceived > 0)
                    {
                        ProcessDataFromClient(socket, segment,
                            dataReceived);
                    }
                }
            }
        }
    }
}

void TCPServer::ProcessNewClient(TCPSocketPtr socket, SocketAddress address)
{
    std::cout << "New client: " << address.mSockAddr.sa_data << std::endl;
}

void TCPServer::ProcessDataFromClient(TCPSocketPtr socket, char* data, int dataLen)
{
    std::cout << "Output: " << data << std::endl;
    const char* strToAdd = " echo";

    size_t newStrLen = dataLen + strlen(strToAdd) + 1;

    char* s = (char*)malloc(newStrLen);

    strcpy_s(s, newStrLen, data);
    strcat_s(s, newStrLen, strToAdd);

    socket->Send(data, strlen(data) + 1);

    free(s);
}