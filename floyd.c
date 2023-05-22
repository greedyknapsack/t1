#include<stdio.h>
#define INF 9999
void Print(int V,int G[V][V],int t)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            printf("%d\t",G[i][j]);
        printf("\n");
    }
}
void floyd(int V,int G[V][V],int D[V][V],int P[V][V])
{
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            {
                D[i][j]=G[i][j];
                P[i][j]=(G[i][j]==INF||i==j)?-1:i;
            }
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(D[i][j]>D[i][k]+D[k][j])
                    {
                        D[i][j]=D[i][k]+D[k][j];
                        P[i][j]=P[k][j];
                    }
    printf("Shortest path matrix:\n");
    Print(V,D,0);
    printf("Predecessor Matrix:\n");
    Print(V,P,1);
}
void main()
{
    int V=5;
    int graph[5][5] = { { 0, 3, 8, INF, -4 },
                        { INF, 0, INF, 1, 7 },
                        { INF, 4, 0, INF, INF },
                        { 2, INF, -5, 0, INF },
                        { INF, INF, INF, 6, 0 } };
    int D[V][V],P[V][V];
    // Print the solution
    floyd(V,graph,D,P);
    
}
