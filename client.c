/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 6-To perform IPC using Shared Memory. Client receives expression 4+3+2. 
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main()
	{
	 int shmid;
	 void *addr=NULL;
	 shmid=shmget(97,100,IPC_CREAT|0666);		//Create shared memory
	 addr=shmat(shmid,NULL,0);			//Attach shared memory to program address space
	 sprintf(addr,"4+3+2");				//Write to shared memory
	 printf("\nClient\n\nExpression written to shared memory\n");
	 shmdt(addr);
	}


/*
OUTPUT

Client

Expression written to shared memory
*/
