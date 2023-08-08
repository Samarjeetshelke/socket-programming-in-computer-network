#include<stdio.h>
#include<string.h>

void dijkstras(int n,int s,int cost[10][10],int dist[10]){
    int v;
    int min,count=1;
    int visited[10];

    for(int i=0;i<n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;

    while (count<=n)
    {   
        min=999;
        for(int i=0;i<n;i++){
            if(visited[i]==0&&dist[i]<min){
                min=dist[i];
                v=i;
            }
        } 
        visited[v]=1;

        for(int i=0;i<n;i++){
            if(dist[i]>dist[v]+cost[v][i]){
                dist[i]=dist[v]+cost[v][i];
            }
        }
        count++;
    }
    
}

void main(){
    int i,j,n,s,cost[10][10],dist[10];
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d",&s);
    dijkstras(n,s,cost,dist);
    printf("\nThe distance: ");

    for(i=0;i<n;i++){
        printf("\n%d",dist[i]);
    }
}