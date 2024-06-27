#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(SOCKET connfd)
{
    char buff[MAX];
    int n;

    // infinite loop for chat
    for (;;)
    {
        memset(buff, 0, MAX);

        // read the message from client and copy it in buffer
        recv(connfd, buff, sizeof(buff), 0);
        
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        memset(buff, 0, MAX);
        n = 0;

        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;

        // and send that buffer to client
        send(connfd, buff, strlen(buff) + 1, 0);

        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Server Exit...\n");
            break;
        }
    }
}

// Driver function
int main()
{
    SOCKET sockfd, connfd;
    int len;
    struct sockaddr_in servaddr, cli;

    // Initialize Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failed to initialize Winsock");
        exit(EXIT_FAILURE);
    }

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET)
    {
        printf("socket creation failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Socket successfully created..\n");
    memset(&servaddr, 0, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if (bind(sockfd, (SA *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
    {
        printf("socket bind failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if (listen(sockfd, 5) == SOCKET_ERROR)
    {
        printf("Listen failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd == INVALID_SOCKET)
    {
        printf("server accept failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("server accept the client...\n");

    // Function for chatting between client and server
    func(connfd);

    // After chatting close the socket
    closesocket(sockfd);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}