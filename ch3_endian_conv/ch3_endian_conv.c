//
//  main.c
//  ch3_endian_conv
//
//  Created by maytrue on 10/6/16.
//  Copyright (c) 2016 HappyIterating. All rights reserved.
//

#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, const char * argv[]) {

    uint16_t host_port = 0x1234;
    uint16_t net_port;
    uint32_t host_addr = 0x12345678;
    uint32_t net_addr;
    
    net_port = htons(host_port);
    net_addr = htonl(host_addr);
    
    printf("host order port: %#x \n", host_port);
    printf("net order port: %#x \n", net_port);
    
    printf("host order address: %#x \n", host_addr);
    printf("net order address: %#x \n", net_addr);
    
    return 0;
}
