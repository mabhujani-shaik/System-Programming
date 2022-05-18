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
	struct sockaddr_in servaddr;
	char cmsg[MAX];
	char smsg[MAX];
	socklen_t slen;
	int socketfd,mlen,structlen;

	//memset(&cliaddr, 0, clen);
	structlen = sizeof(sockaddr_in);
	memset(&servaddr, 0, structlen);
	memset(&smsg, 0, MAX);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8026);

	
	socketfd = socket(AF_INET,SOCK_STREAM,0);
	//bind(socketfd, (const struct sockaddr *)&cliaddr, clen);
	//listen(socketfd, 5);
	connect(socketfd,(struct sockaddr *)&servaddr, structlen);
	while (true ){
		
			write(1,"enter your Message for server: ",31);
			mlen = read(0,cmsg,MAX);
			mlen = write(socketfd,cmsg,strlen(cmsg));
			if(strcmp(cmsg,"bye\n") == 0 )
			{
				close(socketfd);
				break;
			}
				write(1,"Message from server to client: ",31);
				mlen = read(socketfd,smsg,MAX);
				write(1,smsg,strlen(smsg));

				if(strcmp(smsg,"bye\n")==0)
				{
					close(socketfd);
					break;
				}
		
		}
}
	












