//program to implement fifo
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAX 256
using namespace std;
int main()
{
	char filename[] = "fifotest";
	int fifofd,ret;
	char readbuff[MAX];
