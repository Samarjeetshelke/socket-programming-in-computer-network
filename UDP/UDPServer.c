
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>


void main(int narg,char **argv){
	
	char *ip="127.0.1.1";
	int port;
	int sch,bch;
	struct sockaddr_in serveradr;
	socklen_t ssize;
	char buffer[1024];
	
	if(narg!=2){
		printf("\nWrongArguments....");
		exit(0);
	}
	port=atoi(argv[1]);

	sch=socket(AF_INET,SOCK_DGRAM,0);
	if(sch<0){
		printf("\nError in socket");
		exit(0);
	}
	

	memset(&serveradr,'\0',sizeof(serveradr));
	serveradr.sin_family=AF_INET;
	serveradr.sin_port=htons(port);
	serveradr.sin_addr.s_addr=inet_addr(ip);

	bch=bind(sch,(struct sockaddr*)&serveradr,sizeof(serveradr));
	if(bch<0){
		printf("\nError in binding...\n");
	}
	
	ssize=sizeof(serveradr);
	bzero(buffer,1024);
	recvfrom(sch,buffer,1024,0,(struct sockaddr*)&serveradr,&ssize);
	printf("\nThe msg from client: %s",buffer);
	
printf("\nhi\n");
}

