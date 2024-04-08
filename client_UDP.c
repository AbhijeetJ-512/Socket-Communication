#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#define BUFSIZE 50

int main(int argc, char **argv)
{
    int client_socket, port, message_length;
    struct sockaddr_in server_address;
    char message[BUFSIZE];
    if (argc != 3)
    {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("Socket not formed\n");
        exit(2);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = atoi(argv[2]);
    inet_aton(argv[1], &server_address.sin_addr); // converts string format to binary2

    while (1)
    {
        printf("Enter message:");
        fgets(message, BUFSIZE, stdin);

        sendto(client_socket, message, BUFSIZE, 0, (struct sockaddr *)&server_address, sizeof(server_address));
    }
    close(client_socket);
}