//
//  util.c
//  NetworkProgramming
//
//  Created by maytrue on 10/6/16.
//  Copyright (c) 2016 HappyIterating. All rights reserved.
//

#include "util.h"
#include <stdio.h>

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
