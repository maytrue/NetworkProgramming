//
//  main.c
//  ch1
//
//  Created by maytrue on 10/6/16.
//  Copyright (c) 2016 HappyIterating. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "util.h"


int main(int argc, const char * argv[]) {
    
    struct sockaddr_in server_addr;
   
    if (argc != 2) {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }
    char *port_str = (char *)argv[1];
    
    int server_socket;
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket() error");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(port_str));
    
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr) == -1)) {
        error_handling("bind() error");
    }
    
    if (listen(server_socket, 5) == FAIL) {
        error_handling("listen() error");
    }
    
    
    socklen_t client_addr_size;
    struct sockaddr_in client_addr;
    int client_socket;
    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
    
    if (client_socket == FAIL) {
        error_handling("accept() error");
    }
    
    char message[] = "hello world";
    write(client_socket, message, sizeof(message));
    close(client_socket);
    close(server_socket);
    
    
    return 0;
}


