//Program to write data into shared Memory
#include <iostream>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#define MAX 256
using namespace std;

int main() 
{
	key_t key;
	int shmid;
	char *msg;

	key = ftok("mabhujani",65);
	shmid = shmget(key,1024,0666 |IPC_CREAT);
	if (shmid == -1)
	{
		perror("Error Creating Shared Memory");
		exit(EXIT_FAILURE);
	}
	msg = (char *) shmat(shmid,(void *)0,0);
	write(1,"Enter your data to Store: ",25);
	read(0,msg,MAX);
	memset(msg,0,MAX);
	write(1,"rewrite the shared memory",28);
	read(0,msg,MAX);

	cout << "Data Written to shared Memory" << msg << endl;
       shmdt(msg);

	return 0;
}	

