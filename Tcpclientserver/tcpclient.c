#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(SOCKET sockfd) {
    char buff[MAX];
    int n;

    for (;;) {
        memset(buff, 0, sizeof(buff));
        printf("Enter the string : ");
        n = 0;

        while ((buff[n++] = getchar()) != '\n')
            ;

        if (send(sockfd, buff, sizeof(buff), 0) == SOCKET_ERROR) {
            perror("send failed");
            break;
        }

        memset(buff, 0, sizeof(buff));
        if (recv(sockfd, buff, sizeof(buff), 0) == SOCKET_ERROR) {
            perror("recv failed");
            break;
        }

        printf("From Server : %s", buff);

        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in servaddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        perror("socket creation failed");
        WSACleanup();
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) {
        perror("connection with the server failed");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("connected to the server..\n");

    // function for chat
    func(sockfd);

    // close the socket
    closesocket(sockfd);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}