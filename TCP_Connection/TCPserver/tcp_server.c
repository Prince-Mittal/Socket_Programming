#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(){
	char server_message[256] = "You have been successfully connected to the server";

	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//binding the socket to IP and Port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	//listen
	listen(server_socket, 1);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	//Send message to the client
	send(client_socket, server_message, sizeof(server_message), 0);
	
	//close the socket
	close(server_socket);
	return 0;
}
