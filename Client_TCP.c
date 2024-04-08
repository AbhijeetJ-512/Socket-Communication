#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFLEN 1024  //buffer length

int main(int argc, char **argv)
{
    int n;
    int sd,port;
    struct sockaddr_in server;
    char buf[BUFLEN];

    port = atoi(argv[1]);

    //create a Stream socket
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr,"cant create a socket\n");
        exit(1);
    }

    //fill the structure fileds with values
    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sd,(struct sockaddr *)&server, sizeof(server)) == -1)
    {
        fprintf(stderr,"Can't connect\n");
        exit(1);
    }
    printf("Enter message\n");
    scanf("%s",buf);
    write(sd,buf,sizeof(buf));
    n  =read(sd,buf,sizeof(buf));
    printf("%s\n",buf);
    close(sd);
}