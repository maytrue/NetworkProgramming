//
//  hello_client.c
//  NetworkProgramming
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
    
    char message[30];
    
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT> \n", argv[0]);
        exit(1);
    }
    
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == FAIL) {
        error_handling("socket() error");
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == FAIL) {
        error_handling("connect() error");
    }
    
    int str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == FAIL) {
        error_handling("read() error");
    }
    
    printf("Message from server : %s \n", message);
    close(sock);
    
    return 0;
}