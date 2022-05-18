//TCP client program
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#define SERVERIP "127.0.0.1"
#define MAX 256
using namespace std;

int main()
{
        struct sockaddr_in servaddr;
        memset(&servaddr,0,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(SERVERIP);
        servaddr.sin_port=htons(8026);

        char cmsg[MAX];
	char smsg[MAX];
        memset(cmsg,0,sizeof(cmsg));
        socklen_t clen;
        int sockfd,slen,mlen;

        //create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0){
            cout << "socket error" << endl;
            return -1;
        }
       // cout << "socket creation successfully" << endl;

        /*int b = bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
        if(b < 0){
            perror(" binding error: ");
            return -1;
        }
       // listen(sockfd, 5);        
       // cout << "listening on port 8026" << endl;*/
        //clen = sizeof(cliaddr);

    	connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr));
	while(1)
	{

			write(1,"Enter Your Messge for the server: ",34);
			mlen = read(0,cmsg,MAX);
			mlen=write(sockfd,cmsg,strlen(cmsg));
			cout << "sent to server" << endl;
			if ( strcmp(cmsg,"bye\n") == 1)
			{
				close(sockfd);
				break;
			}
			mlen = write(1, "Message from server to the client ",33);
			mlen =read(sockfd,smsg,MAX);
			write(1,smsg,strlen(smsg));
       	}
}
