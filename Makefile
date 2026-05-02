all: server client
server: 
	gcc tcpserver.c -o tcpserver
client:
	gcc tcpclient.c -o tcpclient
