#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed!" << std::endl;
        return 1;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(PORT);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection to server failed!" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Connected to server!" << std::endl;

    while (true) {
        std::cout << "Client: ";
        std::cin.getline(buffer, BUFFER_SIZE);
        send(clientSocket, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cout << "Server disconnected." << std::endl;
            break;
        }
        std::cout << "Server: " << buffer << std::endl;
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}