#include <stdio.h>
#include <sys/types.h>     
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <netdb.h>

#define IP "127.0.0.1"
#define PORT "9002"

void* threadas(void * arg);

struct clientinfo{

struct addrinfo addr;
int fd;

}


int main(){

    int sock;

    struct addrinfo temp, *addr;

    pthread_t threads[10];
    struct addrinfo clients[10];

    memset(&temp, 0, sizeof(temp));
    temp.ai_family = AF_INET;
    temp.ai_socktype = SOCK_STREAM;

    getaddrinfo(IP, PORT, &temp, &addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    bind(sock, addr->ai_addr, addr->ai_addrlen);

    listen(sock, 10);

    for (int i = 0; 1; ++i){

        int fd = accept(sock, &clients[i]->ai_addr, &clients[i]->ai_addrlen);

        struct clientinfo client;

        client.fd = fd;
        client.addr = clients[i]; 

        pthread_create(&threads[0], NULL, threadas, (void *) client);
    }

  

    //pthread_create(&threads[0], NULL, threadas, (void *) a);


    //pthread_join(threads[0], NULL); 

    return 0;
}


void* threadas(void * arg){

    pthread_t thread;

    int *client = (int *) arg;

    pthread_create(&thread, NULL, recv_msg, (void *) client);

    while  ( 1 ){

        recv(client->fd, msg, 256, 0);


    }

    pthread_exit(NULL); 

    return NULL;
}

void* recv_msg(void *arg){

    int *client = (int *) arg;

    while ( 1 ){




    }

    pthread_exit(NULL);

    return NULL;
}
