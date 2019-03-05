/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 6-To perform IPC using Shared Memory. Server evaluates expression received by Client.
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main()
	{
	 int shmid,l,i,result=0;
	 char str[20];
	 void *addr=NULL;
	 shmid=shmget(97,100,IPC_CREAT|0666);		//Create shared memory
	 addr=shmat(shmid,NULL,0);			//Attach shared memory to program address space
	 sscanf(addr,"%s",str);				//Read from shared memory
	 l=strlen(str);
	 for(i=0;i<l;i++)				//For evaluating the expression
	 	{
		 if(isdigit(str[i]))
		 	result=result+str[i]-48;	//If it is a digit,add it and for ASCII adjustment, subtract 48
		}
	 printf("\nServer\n\nResult = %d\n",result);
	 shmdt(addr);
	}

/*
OUTPUT

Server

Result = 9
*/
