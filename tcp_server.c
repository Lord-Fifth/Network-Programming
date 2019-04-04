/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 8 - IPC using TCP (Server)
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()                      //Main method commences here
{
	char buff[100];
    int sock_desc,k; 
	struct sockaddr_in serv_addr;
	struct sockaddr_in ac;
	memset(&ac,0,sizeof(ac));              	 //Setting memory to accept string
	memset(&serv_addr,0,sizeof(serv_addr)); 
	sock_desc=socket(AF_INET,SOCK_STREAM,0);  //Creating socket in server
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
		printf("Binding Failed! \n");   //Binding failed
	if(listen(sock_desc,5)!=0)              //Listening to client
	{
		printf("LIstening failed!\n");  //Listening failed
		exit(0);
	}
	int len=sizeof(ac);
	int accpkt=accept(sock_desc,(struct sockaddr*)&ac,&len); 
	read(accpkt,buff,sizeof(buff));         //Getting string from client
	printf("Data acquired:   %s\n",buff);   //Printing data acquired
	close(sock_desc);   			//Closing the connection
}

/*
OUTPUT
Data acquired:   Aditya
*/
