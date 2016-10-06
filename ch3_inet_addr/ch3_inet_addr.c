//
//  main.c
//  ch3_inet_addr
//
//  Created by maytrue on 10/6/16.
//  Copyright (c) 2016 HappyIterating. All rights reserved.
//

#include <stdio.h>
#include <arpa/inet.h>

void convert_addr(char *addr) {
    uint32_t conv_addr = inet_addr(addr);
    if (conv_addr == INADDR_NONE) {
        printf("Error conv address\n");
    } else {
        printf("Net order address: %lx \n", conv_addr);
    }
}

int main(int argc, const char * argv[]) {
   
    
    char *addr1 = "1.2.3.4";
    char *addr2 = "1.2.3.256";
    
    convert_addr(addr1);
    convert_addr(addr2);
    
    return 0;
}
