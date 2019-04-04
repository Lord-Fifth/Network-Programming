/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 9 - IPC using UDP (Server)
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()                      //Main method commences here
{
	char buf[100];
        int sock_desc,k,s; 
        struct sockaddr_in serv_addr;
	struct sockaddr_in ac;
        memset(&ac,0,sizeof(ac));               //Setting memory to accept string
	memset(&serv_addr,0,sizeof(serv_addr)); 
	sock_desc=socket(AF_INET,SOCK_DGRAM,0);  //Creating socket in server
	if(sock_desc==-1)
	{
		printf("Error in socket creation! \n");
		exit(1);
	}
 

 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = 3000; 
        k=bind(sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //Server binds to the socket of client

	if(k!=0)
		printf("Binding Failed! \n");
         s=sizeof(serv_addr);
        k=recvfrom(sock_desc,&buf,100,0,(struct sockaddr*)&serv_addr,&s );
	if(k< 0)
	{
		printf("Recieving failed \n");
         }
        printf("Data acquired:   %s\n",buf);
        close(sock_desc);
}

/*
OUTPUT
Data acquired:   Aditya
*/
