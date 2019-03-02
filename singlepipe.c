/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 5(A)-To perform IPC using Single Pipe. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h> // Header file for pipe system call

int main()
	{
 	// WE USE A SINGLE PIPE. PIPE IS CREATED USING PIPE(). 
 	// INT FD[2] - FD[0] IS FOR READEND, FD[1] IS WRITEEND
 	// A MESSAGE IS SENT BY PARENT VIA FD[1] AND THE MESSAGE IS RECEIVED BY CHILD VIA FD[0]
 	// -- IMPORTANT - CLOSE ALL THE READ AND WRITE ENDS!
 
	 int fd[2],len,pid;
	 char message[16]="This is a test.";
	 char reply[16]=" ";
	 len=strlen(message);

	 pipe(fd);
	 pid=fork();

	 if(pid<0)
		 {
		  printf("Error");
	  	  exit(0);
	 	}
	 else if(pid>0)  			//PARENT PROCESS
	 	{
	  	 close(fd[0]);			
	  	 write(fd[1],message,len);	//Parent sending message.
	  	 printf("\nMessage sent by parent( pid - %d ): %s \n",getpid(),message);
	  	 close(fd[1]);
	 	}
	 else					//CHILD PROCESS
	 	{
	  	 close(fd[1]);
	  	 read(fd[0],reply,len);		//Child receiving message.
	  	 printf("\nMessage received by child( pid - %d ): %s \n",getpid(),reply);
	  	 close(fd[0]);
	 	}
	 return 0;
	}

/*
OUTPUT


Message sent by parent( pid - 3262 ): This is a test. 

Message received by child( pid - 3263 ): This is a test. 
*/

