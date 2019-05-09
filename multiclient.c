
//MULTIUSER CHAT USING TCP
//CLIENT PROCESS
//AUTHOR AISWARYA M
//ROLL NO 7

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()                            //main method commences here
{

        char buf[100];
        int sock_desc,k; 
        struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	sock_desc=socket(AF_INET,SOCK_STREAM,0);     //creating socket in client
	if(sock_desc==-1)
	{
		printf("Error in socket creation! \n");  //error in socket creation
		exit(1);
	}
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=INADDR_ANY;
	client.sin_port=3010;
	k=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));  //connecting to server

        if (k==-1)
        {

           	printf("Error in connecting to server! \n");  //error in connecting to server
		exit(1);

        }
        while(1)
	{
        gets(buf);
	k=send(sock_desc,buf,100,0);        //sending data for server
	if(k==1)
	{
		printf("Sending failed\n");    //sending failed
		exit(1);
	}
	if (strcmp(buf,"e")==0)
	{
	close(sock_desc);                      //closing connection
	exit(0);
	}
	if (recv(sock_desc,buf,1024,0)<0)      
		printf("Error");
	else
		printf("%s \n",buf);           //printing acknowledgement from server
	}
	return 0;
}

//OUTPUT
/*
client 1 : hey
client 2: hello
*/
