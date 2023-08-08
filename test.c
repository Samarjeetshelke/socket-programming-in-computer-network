#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){

    char ip[20];
    char ipmsk[20];

    printf("\nEnter the IP: ");
    scanf("%s",ip);
        printf("\nEnter the IP: ");
        scanf("%s",ipmsk);
    int ip4[4];
    int mask[4];

    sscanf(ip,"%d.%d.%d.%d",&ip4[0],&ip4[1],&ip4[2],&ip4[3]);
    sscanf(ipmsk,"%d.%d.%d.%d",&mask[0],&mask[1],&mask[2],&mask[3]);

    int net[4];
    int host[4];
    int i=0;

    while(i<4){
        net[i]=(ip4[i]&mask[i]);
        host[i]=(ip4[i]&~mask[i]);
        i++;
    }

    printf("\nNetwork ID: %d.%d.%d.%d",net[0],net[1],net[2],net[3]);
    printf("\nhost ID: %d.%d.%d.%d",host[0],host[1],host[2],host[3]);


}