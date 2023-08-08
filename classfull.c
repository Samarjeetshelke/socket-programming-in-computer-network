#include<stdio.h>
#include<stdlib.h>

int validornot(char *s){
    int flg=0;
    int i=0;
    while (s[i]!='\n')
    {
        if(s[i]=='.'){
            flg++;
        }
        i++;
    }
    if(flg==3){
        return 1;//valid
    }
    return 0;
    
}
void main(){
    char ip[20];
    int i;
    int x;
    char temp[4];//put size moer ther three plz
    int flg=0;
    xx:
    printf("Enter IP address: ");
    scanf("%s",ip);
    if(!validornot(ip)){
        printf("Invalid input!!!");
        printf("\nTry again...");
        goto xx;
    }
    i=0;
    while(ip[i]!='.'){
        temp[i]=ip[i];
        i++;
    }
    x=atoi(temp);

    if(x>0&&x<128){
        printf("\nThe IP is belong to Class A..");
        flg=1;
    }
    else if(x>=128&&x<192){
        printf("\nThe IP is belong to Class B...");
        flg=2;
    }else if(x>=192&&x<224){
        printf("\nThe IP is belong to Class C....");
        flg=3;
    }
    else if(x>=224&&x<=239){
        printf("\nThe IP is belong to Class D.....");
    }
    else if(x>239&&x<=255){
        printf("\nThe IP is belong to Class E......");
    }
    else{
        printf("\nInvalid IP Address!!!");
    }
    
    printf("\nThe Newtork Id :");
    if(x<224){
         i=0;
    while(i<20){
        if(ip[i]=='.'){
            flg--;
        }
        if(flg==0)
        {
            break;
        }
        printf("%c",ip[i]);
        i++;
    }
    i++;
    }
    else{
        printf("  Not Defined! (This Ip May be reserved or multicast)");
    }
    
    printf("\nThe Host ID : ");

    if(x<224){
        
    while(ip[i]!='\0'){
        printf("%c",ip[i]);
        i++;
    }
    }
    else{
            printf("  Not Defined! (This Ip May be reserved or multicast)");
    }

 

}