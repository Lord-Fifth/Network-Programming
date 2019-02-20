
// CPP code to create three child process of a parent 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main() 
	{int pid, pid1, pid2; 
        pid = fork(); 
  
 	  // If fork() returns zero then it means it is child process. 
        if (pid == 0) 
		{sleep(3);
		printf("First Child --> pid = %d and ppid = %d\n", 
                getpid(), getppid()); 
   	        } 
	else 
		{pid1 = fork(); 
	        if (pid1 == 0)
			{sleep(2); 
            		printf("Second Child --> pid = %d and ppid = %d\n", 
                   	getpid(), getppid()); 
        		} 
        	else 
			{pid2 = fork(); 
                	if (pid2 == 0) 
				{printf("Third Child --> pid = %d and ppid = %d\n", 
                                getpid(), getppid()); 
				} 
  
            // If value returned from fork() in not zero and >0 that means this is parent process. 
           	        else 
				{sleep(3); 
                                 printf("parent --> pid = %d\n", getpid()); 
            			} 
        		} 
    		} 
	return 0; 
	} 

