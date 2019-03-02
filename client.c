/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 6-To perform IPC using Shared Memory for client. 
*/

#include<stdio.h>
#include<sys/shm.h>

int main()
	{
	 int shmid,addr;
	 char str1[10]="";
        
	 key_t key;
 	 key=100;

	 shmid=shmget(key,100,IPC_CREAT|0666);
	 addr=shmat(shmid,NULL,0);

	 printf(" Enter the expression: ");
         scanf("%s",str1);

	 sprintf(addr,str1);
	 shmdt(addr);
       
	 return 0;

	}
