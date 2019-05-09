//MULTIUSER CHAT USING TCP
//SERVER PROCESS
//AUTHOR :AISWARYA M
//ROLL NO 7


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()                      //main method commences here
{
	char buf[100],rv[100];
        int sock_desc,k,childpid,accpkt; 
        struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr)); 
	sock_desc=socket(AF_INET,SOCK_STREAM,0);  //creating socket in server
	if(sock_desc==-1)
	{
		printf("Error in socket creation! \n");
		exit(1);
	}
 

 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = 3010; 

	k=bind(sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //server binds to the socket of client

	if(k!=0)
		printf("Binding Failed! \n");   //binding failed
	int x=listen(sock_desc,10);             //listening to client
	if(x!=0)             
	{
		printf("LIstening failed!\n");  //listening failed
		exit(0);
	}
	while(1)
	{
	
	int len=sizeof(serv_addr);
	accpkt=accept(sock_desc,(struct sockaddr*)&serv_addr,&len); //creation of temporary socket descriptor
	if((childpid=fork())==0)                //client creation
		{
		while(1)
		{
			recv(accpkt,buf,1024,0);   //receiving from client
			printf("%s\n",buf);
			gets(rv);  
			send(accpkt,rv,sizeof(rv),0);     //acknowledging client
		}
		}
	}
	close(accpkt);               //closing temporary file descriptor

}

//OUTPUT
/*
hey
hello
*/


