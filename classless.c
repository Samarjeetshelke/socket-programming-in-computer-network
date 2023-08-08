#include<stdio.h>
#include<stdlib.h>

void dijkstra(int n,int s,int cost[10][10],int dist[10]){
    int v;
    int min,count=1;
    int visited[10];

    for(int i=1;i<=n;i++){
            visited[i]=0;
            dist[i]=cost[s][i];
    }
    dist[s]=0;
    visited[s]=1;


    while(count<=4){

            min=999; 
            for(int i=1;i<=n;i++){
                if(min>dist[i]&&visited[i]==0){
                    min=dist[i];
                    v=i;
                }
            }
            visited[v]=1;
            for(int i=1;i<=n;i++){
                if(dist[i]>dist[v]+cost[v][i]){
                    dist[i]=dist[v]+cost[v][i];
                }
            }

        count++;
    }
}
void main(){
    int n;

    int i,s,j,cost[10][10],dist[10];

    printf("\nEter the number of node: ");
        scanf("%d",&n) ;

    printf("\nEnter the cost matrix: ");
    for(i=1;i<=n;i++){
        printf("\n");
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }   

    printf("\nEnter the source: ");
        scanf("%d",&s);

        printf("\nThe distance to all node from %d\n",s);
        dijkstra(n,s,cost,dist);

        for(i=1;i<=n;i++){
            printf("\n%d->%d: %d",s,i,dist[i]);
        }
}
