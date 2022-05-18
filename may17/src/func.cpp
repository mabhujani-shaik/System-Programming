//Function to collect server ip address and port number and return sockfd
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#define MAX 256
#include "../include/func.h"
using namespace std;
//#define port 8026
//#define ip "127.0.0.1"

int createsocket(const char *serverip, int portno)//creating socket and returning socket id
{
	struct sockaddr_in servaddr;
	int sockfd, mlen,slen;
	//socklen_t clen;

	slen = sizeof(sockaddr_in);
	memset(&servaddr,0,slen);
	//updating server details
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(serverip);
	servaddr.sin_port = htons(portno);
	//TCP CONNECTION
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	cout << sockfd;
	if( sockfd < 0)
	{
		cout << "socket have not created" << endl;
		exit(EXIT_FAILURE);
	}
        mlen=bind(sockfd,(struct sockaddr *) &servaddr, slen);
	if( mlen < 0)
	{
		cout << "socket was not binded" << endl;
		exit(EXIT_FAILURE);
	}
	mlen = listen(sockfd,5);
	if ( mlen < 0)
	{
		cout << "server is not listening" << endl;
		exit(EXIT_FAILURE);
	}
	return sockfd;
}

void createsharedmemory()//creating shared memory
{
	key_t key;
	int shmid;
      	int *inc; 	
	key = ftok("/home/cguser26/may17/secretfile",65);
	shmid = shmget(key,5,0666 | IPC_CREAT);
	if( shmid == -1)
	{
		perror("error creating shared memory");
		exit(EXIT_FAILURE);
	}

	inc = (int *) shmat(shmid,(void *)0,0);
	*inc = 0;	
}
void distroysharedmemory(int value)//distroy shared memory
{
	key_t key = ftok("/home/cguser26/may17/secretfile", 65);
	int id = shmget(key,5,0666);
	//shmdt(value);
	shmctl(id,IPC_RMID,NULL);

}
short attachintegervalue()//attaching shared memory
{
	key_t key;
	int shmid;
	int val;
      	short *inc; 	
	key = ftok("/home/cguser26/may17/secretfile",65);
	shmid = shmget(key,5,0666);
	if( shmid == -1)
	{
		perror("error creating shared memory");
		exit(EXIT_FAILURE);
	}
	inc = (short *)shmat(shmid,(void *)0,0);
	*inc = *inc + 1;	
	val = *inc;
	//shmdt((void *)inc);
	return val;
}
	

		
	
			

		
	

































