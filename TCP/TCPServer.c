#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

void main(){
	char *ip="127.0.1.1";
	int port=1300;
	int sch;
	socklen_t ssize;
	int bch,cch;
	char buffer[1024];
	struct sockaddr_in serveradr;

	sch=socket(AF_INET,SOCK_STREAM,0);
	if(sch<0){
		printf("\nError in socket...\n");
		exit(0);
	}
	
	memset(&serveradr,'\0',sizeof(serveradr));
	serveradr.sin_family=AF_INET;
	serveradr.sin_port=port;
	serveradr.sin_addr.s_addr=inet_addr(ip);
	bch=bind(sch,(struct sockaddr*)&serveradr,sizeof(serveradr));
	if(bch<0){
		printf("\nError in binding...\n");
		exit(0);
	}
	
	listen(sch,5);
	
	while(1){
		ssize=sizeof(serveradr);
		cch=accept(sch,(struct sockaddr*)&serveradr,&ssize);
		bzero(buffer,1024);
		recv(cch,buffer,1024,0);
		printf("\nClient: %s",buffer);
	}
	
	printf("\nDone");

}
