#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>

void main(){
	char *ip="127.0.1.1";
	int port=1300;
	int sch;
	socklen_t ssize;
	int bch,cch;
	char buffer[1024];
	struct sockaddr_in cadr;

	memset(&cadr,'\0',sizeof(cadr));
	cadr.sin_family=AF_INET;
	cadr.sin_port=port;
	cadr.sin_addr.s_addr=inet_addr(ip);
	
	printf("\nDone\n");
	sch=socket(AF_INET,SOCK_STREAM,0);
	if(sch<0){
		printf("\nError in socket...\n");
		exit(0);
	}

	printf("\nDone1");
	
	connect(sch,(struct sockaddr*)&cadr,sizeof(cadr));
	printf("\nThe client is now connected..\n");
	//while(1){
		//ssize=sizeof(serveradr);

		bzero(buffer,1024);
		time_t currenttimex;	
		time(&currenttimex);
		strcpy(buffer,ctime(&currenttimex));
		send(sch,buffer,1024,0);
		printf("\nMsg is send..");
		//recv(cch,buffer,1024,0);
		//printf("\nClient: %s",buffer);
	//}
	
	printf("\nDonex");



	
}
