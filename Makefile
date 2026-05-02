CC = gcc
CFLAGS = -Wall -Wextra
 
all: tcpserver tcpclient
 
tcpserver: tcpserver.c
	$(CC) $(CFLAGS) tcpserver.c -o tcpserver
 
tcpclient: tcpclient.c
	$(CC) $(CFLAGS) tcpclient.c -o tcpclient
 
clean:
	rm -f tcpserver tcpclient
