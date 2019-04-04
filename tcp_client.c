/* Roll no. : R6-06
   Author : Aditya Suresh
   EXPERIMENT 8 - IPC using TCP (Client)
*/


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()                            //Main method commences here
{

    char buf[100];
    int sock_desc,k; 
    struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	sock_desc=socket(AF_INET,SOCK_STREAM,0);     //Creating socket in client
	if(sock_desc==-1)
	{
		printf("Error in socket creation! \n");  //Error in socket creation
		exit(1);
	}
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=INADDR_ANY;
	client.sin_port=3000;
	k=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));  //Connecting to server

        if (k==-1)
        {

           	printf("Error in connecting to server! \n");  //Error in connecting to server
		exit(1);

        }
	printf("Enter the data to be send:  ");   //Reading data from user
	scanf("%s",buf);
	k=send(sock_desc,buf,100,0);       	 //Sending data for server
	if(k==1)
	{
		printf("Sending failed\n");    //Sending failed
		exit(1);
	}
	close(sock_desc);                      //Closing connection
	exit(0);
	return 0;
}

/*
OUTPUT
Enter the data to be send:  Aditya
*/




