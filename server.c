/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 6-To perform IPC using Shared Memory for server. 
*/

#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main()
	{
	 int shmid,addr,i,j,result;
	 int num[5];
         char str2[10]=" ";
         //randomize();
	 key_t key,new_key;
 	 key=100;
	 j=0;

	 shmid=shmget(key,100,IPC_CREAT|0666);
	 addr=shmat(shmid,NULL,0);

	 sscanf(addr,"%s",str2);
	 shmdt(addr);

	//printf(str2);
	
	 for(i=0;i<strlen(str2)-1;i++)
	 	{
		 switch(str2[i])
			{
			 case '0': num[j++]=0;
				   break;
			 case '1': num[j++]=1;
				   break;
			 case '2': num[j++]=2;
				   break;
			 case '3': num[j++]=3;
				   break;
			 case '4': num[j++]=4;
				   break;
			 case '5': num[j++]=5;
				   break;
			 case '6': num[j++]=6;
				   break;
			 case '7': num[j++]=7;
				   break;
			 case '8': num[j++]=8;
				   break;
			 case '9': num[j++]=9;
				   break;
			}
		 if( str2[i]=='+')
	 		result=num[1]+num[2];

		}

	         printf("Result: %d",result);

	 return 0;

	}
