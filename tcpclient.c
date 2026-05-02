#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

    int socket1 = socket(AF_INET, SOCK_STREAM, 0);
    char buff[255];

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4926);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if(connect(socket1, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("Error in connecting to the server");
        exit(1);
    }

    int n = recv(socket1, buff, sizeof(buff)-1, 0);
    buff[n] = '\0';

    printf("Client Received: %s\n", buff);

    close(socket1);

    return 0;
}
