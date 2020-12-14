#include <stdio.h>
#include <sys/types.h>     
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

int main(){

    int sock, client_sock;

    pthread_t threads[10];

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9002);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // INADDR_ANY

    sock = socket( AF_INET, SOCK_STREAM, 0);

    bind(sock, (struct sockaddr *) &addr, sizeof(addr));

    listen(sock, 10);

    client_sock = accept(sock, NULL, NULL);

    char msg[256] = "Cia serveris !";
    int len = sizeof(msg);

    while ( 1 ){

        send(client_sock, msg, len, 0);

        recv(sock, msg, 256, 0);

        printf("%s\n", msg);

    }

    send(client_sock, msg, len, 0);

    close(sock);

    return 0;
}