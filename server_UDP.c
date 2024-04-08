#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define BUFSIZE 50

int main(int argc, char **argv)
{
    int serversock, clientsock;
    struct sockaddr_in server_address, client_address;
    int client_address_length;
    char message[BUFSIZE];

    if ((serversock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket not created\n");
        exit(1);
    }
    server_address.sin_port = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(serversock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("couldn't bind socket");
        exit(2);
    }
    while (1)
    {
        client_address_length = sizeof(client_address);
        int n = recvfrom(serversock, message, BUFSIZE, 0, (struct sockaddr *)&client_address, &client_address_length);
        message[n] = '\0';
        printf("Message from client %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), message);
    }
    close(serversock);
    return 0;
}
