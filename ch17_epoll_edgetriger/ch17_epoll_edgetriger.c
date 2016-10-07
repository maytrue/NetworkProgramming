//
//  main.c
//  ch17_epoll_edgetriger
//
//  Created by maytrue on 10/7/16.
//  Copyright (c) 2016 HappyIterating. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/event.h>
#include "util.h"

#define MAX_EVENT_COUNT 10

static void kqueue_reg_event(int kq, int fd) {
    struct kevent changes[1];
    EV_SET(&changes[0], fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    kevent(kq, changes, 1, NULL, 0, NULL);
}

int main(int argc, const char * argv[]) {
    
    int server_socket;
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket() error");
    }
    
    char *port_str = (char *)argv[1];
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(port_str));
    
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == FAIL) {
        error_handling("bind() error");
    }
    
    if (listen(server_socket, 5) == FAIL) {
        error_handling("listen() error");
    }
    

    int kq = kqueue();
    kqueue_reg_event(kq, server_socket);
    
    struct kevent events[MAX_EVENT_COUNT];
    while (1) {
        int ret = kevent(kq, NULL, 0, events, MAX_EVENT_COUNT, NULL);
        
        for (int i = 0; i < ret; i++) {
            
            int sock = events[i].ident;
            int data = events[i].data;
            
            if (sock == server_socket) {
                for (int i = 0; i < data; i++) {
                    int client_sock = accept(server_socket, NULL, NULL);
                    kqueue_reg_event(kq, client_sock);
                }
            } else {
                
            }
        }
    }
    
    return 0;
}
