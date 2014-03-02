/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description: This source contains the implementation of server side of the chat application
 *
 *        Version:  1.0
 *        Created:  02/27/2014 08:36:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José Guilherme Vanz (vanz), guilherme.sft@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	struct sockaddr_in server_config, client_config;
	socklen_t size_client, size_server;
	int socket_servidor;

//	char * buffer;
//	buffer = malloc(sizeof(char)*100);
	socket_servidor = socket(PF_INET, SOCK_STREAM, 0); //Create the socket

	memset((struct sockaddr_in *) &(server_config), 0, sizeof(server_config)); //clean memory
	server_config.sin_family = PF_INET;
	server_config.sin_port = htons(4040);
	server_config.sin_addr.s_addr = inet_addr("127.0.0.1");

	size_server = sizeof(server_config);
	int retorno_bind = bind(socket_servidor, (struct sockaddr*)&server_config, size_server );
	if (retorno_bind == -1){
		perror("Error de bind: ");
	}

	int retorno = listen(socket_servidor, 5);

	if(retorno == -1){
		perror("Erro no listen: ");
	}

	size_client = sizeof(client_config);
	int client = accept(socket_servidor, (struct sockaddr*) &client_config , &size_client);

	if(client == -1){
		perror("Error accept: ");
	}else{
		printf("Client connected :)\n");
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */