//this program creates udp client
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#define SERVERIP "127.0.0.1"
#define MAX 256
using namespace std;



int main() 
{
	struct sockaddr_in servaddr;//creating server structure of type sockaddr_in
	char cmsg[MAX] = "Received Message from the Client to server ";
	char smsg[MAX];
	socklen_t clen;
	int socketfd,mlen,slen;

	//memset(&cliaddr, 0, clen);
	memset(&servaddr, 0, sizeof(sockaddr_in)); //setting memory with 0 to avoid garbage at server address
	memset(&smsg, 0, MAX);
	
	servaddr.sin_family = AF_INET;//initializing the server structure
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8026);
	slen = sizeof(sockaddr_in);
	
	socketfd = socket(AF_INET,SOCK_DGRAM,0);//creating socket
	bind(socketfd, (const struct sockaddr *)&servaddr, slen);//binding the socket with network
	//listen(socketfd, 5);
	//connect(socketfd,(struct sockaddr *)&servaddr, structlen);
   	mlen = sendto(socketfd,cmsg,strlen(cmsg),MSG_CONFIRM,(const struct sockaddr *) &servaddr, slen);
	cout << "Message from Client to server has been sent"<< endl;
	mlen=recvfrom(socketfd,smsg,MAX,MSG_WAITALL,(struct sockaddr *) &servaddr,&clen);
	cout << smsg  <<endl;
	close(socketfd);
}
	












