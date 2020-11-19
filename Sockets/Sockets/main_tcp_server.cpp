#include "Shared.h"

int main()
{
    //std::cout << "Server"<<std::endl;
    //TCPServer server;
    //server.DoTCPLoop();

    OutputMemoryStream outputMS;

    TestClass test(1,1,"Cat");

    //std::cout << "Output " <<  << std::endl;

    test.Write(outputMS);


    const char *buffer = outputMS.GetBufferPtr();
    uint32_t sz = outputMS.GetLength();

    TestClass inputTS(2,2,"ABCDEF");

    InputMemoryStream inputMS((char*)buffer, sz);

    inputTS.Read(inputMS);

    //std::cout << "Input " << receivedStr << std::endl;

    system("pause");
}