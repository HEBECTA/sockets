#include <stdio.h>
#include <sys/types.h>     
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(){

    int sock;

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9002);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // INADDR_ANY

    sock = socket( AF_INET, SOCK_STREAM, 0);

    connect(sock, (struct sockaddr *) &addr, sizeof(struct sockaddr));

    char msg[256] = { 0 };

    recv(sock, msg, 256, 0);

    printf("%s\n", msg);

    close(sock);

    return 0;
}