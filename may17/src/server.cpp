//server file or driver file to connect to client
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAX 256
#include "../include/func.h"
using namespace std;



int main() 
{
	struct sockaddr_in cliaddr;
	char smsg[MAX];
	char cmsg[MAX];
	socklen_t clen = sizeof(cliaddr);
	int socketfd,connecfd,mlen,client_id;

	int slen = sizeof(sockaddr_in);
	memset(cmsg,0,MAX);
	memset(&cliaddr, 0, slen);
	socketfd = createsocket("0.0.0.0",8026);
	
	while(1) {
		//coneecting to clients through accept function
		connecfd = accept(socketfd,(struct sockaddr *)&cliaddr, &clen);
		int nof_connections = attachintegervalue(); 
		cout << "totalno of connection: "<< nof_connections << endl;
		client_id = fork();//creating child process
		if (client_id == 0)
		{
			close(socketfd);
			mlen = read(connecfd,cmsg,MAX);
			write(1,"one message from the client: ",29);
			cout << endl;
			write(1,cmsg,MAX);
			write(1,"Enter a message for the client: ",31);
			mlen = read(0,smsg,MAX);
			mlen = write(connecfd,smsg,strlen(smsg));
			exit(0);
		}
		close(connecfd);
		
	}
	close(socketfd);
	distroysharedmemory(1);
}
	











