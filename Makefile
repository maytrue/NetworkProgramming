CC=gcc
CFLAGS=
INCLUDE=-I./

ch1 : ch1_server ch1_client

ch1_server: ch1_server.o util.o
	$(CC) $(CFLAGS) ./output/ch1_server.o ./output/util.o -o ./output/ch1_server   

ch1_server.o : ./ch1_server/hello_server.c  util.h util.c
	$(CC) -c ./ch1_server/hello_server.c $(INCLUDE) -o ./output/ch1_server.o

util.o : util.c util.h
	$(CC) -c util.c -o ./output/util.o


ch1_client: ch1_client.o util.o
	$(CC) $(CFLAGS) ./output/ch1_client.o ./output/util.o -o ./output/ch1_client

ch1_client.o : ./ch1_client/hello_client.c  util.h util.c
	$(CC) -c ./ch1_client/hello_client.c $(INCLUDE) -o ./output/ch1_client.o

