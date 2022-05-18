//Program to demostrate  a race condition
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
int balance =0;
void *computebal( void *arg ) {
	int b,c;
	b = balance;
	for(int i=0; i<5000; i++)
	{
		c = 5000*1234;
	}
	b += 10;
	balance = b;
	return NULL;
}
int main() {
	int i;
	pthread_t pthread_id[200];
	cout << "Balance Before Thread: " << balance << endl;
	for(i =0;i<200;i++)
	{
		pthread_create(&pthread_id[i],NULL,computebal,NULL);
	}
	for(i=0;i<200;i++)
	{
		pthread_join(pthread_id[i],NULL);
	}
	cout << "Balance After Thread: " << balance << endl;
	exit(EXIT_FAILURE);
	return 0;
}
			

