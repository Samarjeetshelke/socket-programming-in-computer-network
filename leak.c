#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    int i=0;
    int noofqueries=6;
    int inputsize=4;
    int outputsize=1;
    int bucketsize=10;
    int storagefill=0;
    int avail;


    while(i<noofqueries){
        avail=bucketsize-storagefill;

        if(avail>=inputsize){
            storagefill+=inputsize;
        }
        else{
            printf("\nNot enough space 4 packets get lost!");
        }
        storagefill-=outputsize;
        printf("\nStorage available: %d output rate: 1",(bucketsize-storagefill));
        i++;
    }
}