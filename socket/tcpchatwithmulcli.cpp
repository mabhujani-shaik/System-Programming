#include <iostream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define SERVERIP "127.0.0.1"
#define MAX 256
using namespace std;



int main() 
{
	struct sockaddr_in servaddr,cliaddr;
	char smsg[MAX];
	char cmsg[MAX];
	socklen_t clen;
	int socketfd,slen,connecfd,mlen,client_id;

		
	slen = sizeof(sockaddr_in);
	memset(&cliaddr, 0, slen);
	memset(&servaddr, 0, slen);
	memset(&cmsg, 0, MAX);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8026);

	
	socketfd = socket(AF_INET,SOCK_STREAM,0);
	bind(socketfd, (const struct sockaddr *)&servaddr, slen);
	listen(socketfd, 5);
	
	while(1) {
			
		connecfd = accept(socketfd,(struct sockaddr *)&cliaddr, &clen);
		client_id = fork();
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
}
	












