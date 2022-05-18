//Program to write data into shared Memory
#include <iostream>
#include <sys/ipc.h>
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

	key = ftok("mabhujani", 65);
	shmid = shmget(key,1024,0666);
	if (shmid == -1)
	{
		perror("Error Creating Shared Memory");
		exit(EXIT_FAILURE);
	}
	msg = (char *) shmat(shmid,(void *)0,0);
//	write(1,"Enter your data to Store: ",25);
//	read(0,msg,MAX);

	cout << "Data Written to shared Memory" << msg << endl;
       	shmdt(msg);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}	

