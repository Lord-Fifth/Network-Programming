/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 3(A)-To Create a parent and three child processes.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main() 
	{
	 int pid, pid1, pid2; 
         pid = fork(); 
  
 	  // If fork() returns zero then it means it is child process. 
         if (pid == 0) 
		{
		 sleep(3);
		 printf("First Child --> pid = %d and ppid = %d\n", getpid(), getppid()); 
   	        } 
	 else 
		{
		 pid1 = fork(); 
	         if (pid1 == 0)
			{
			 sleep(2); 
            		 printf("Second Child --> pid = %d and ppid = %d\n", getpid(), getppid()); 
        		} 
        	 else 
			{
			 pid2 = fork(); 
                	 if (pid2 == 0) 
				{
				 printf("Third Child --> pid = %d and ppid = %d\n", getpid(), getppid()); 
		 		} 
  
            // If value returned from fork() in not zero and >0 that means this is parent process. 
           	        else 
				{
				 sleep(3); 
                                 printf("parent --> pid = %d\n", getpid()); 
            			} 
        		} 
    		} 
	 return 0; 
	} 

/*
OUTPUT

Third Child --> pid = 3345 and ppid = 3342
Second Child --> pid = 3344 and ppid = 3342
parent --> pid = 3342
First Child --> pid = 3343 and ppid = 3342
*/
