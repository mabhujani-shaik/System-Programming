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
	char smsg[MAX] = "Message from the server to Client";
	char cmsg[MAX];
	socklen_t clen;
	int socketfd,slen,connecfd;

		
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

	connecfd = accept(socketfd,(struct sockaddr *)&cliaddr, &clen);
	int mlen=recv(connecfd,cmsg,MAX,0);
	cout << cmsg << endl;
	mlen = send(connecfd,smsg,strlen(smsg),0);
	cout << mlen << "Message sent from the server" <<endl;
	close(connecfd);
}
	












