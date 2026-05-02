#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket < 0){
        perror("Socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4926);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_socket, 1);

    int client_socket = accept(server_socket, NULL, NULL);

    char msg[] = "Hello! from Server here :)";
    send(client_socket, msg, strlen(msg), 0);

    close(client_socket);
    close(server_socket);

    return 0;
}
