CC=gcc
CFLAGS=
INCLUDE=-I./util/

ch1_server: ch1_server.o
	$(CC) $(CFLAGS) $(INCLUDE) -o ch1_server   

ch1_server.o : ./ch1_server/hello_server.c
	$(CC) -c 
