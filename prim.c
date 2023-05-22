#include<stdio.h>
int extractMin(int V,int *q,int *k)
{
    int r=-1;
    for(int i=0;i<V;i++)
        if(q[i]==1&&(r==-1||k[r]>k[i]))
            r=i;
    q[r]=0;
    return r;
}
int prim(int V,int G[V][V],int s)
{
    int queue[V],count=V,tcost=0;
    int key[V],parent[V];
    for(int v=0;v<V;v++)
    {
        queue[v]=1;
        key[v]=999999;
        parent[v]=-1;
    }
    key[s]=0;
    while(count!=0)
    {
        int u=extractMin(V,queue,key);
        if(parent[u]!=-1)
        {
            printf("%d-%d-%d\n",parent[u],u,G[parent[u]][u]);
            tcost+=G[parent[u]][u];
        }
        count--;
        for(int v=0;v<V;v++)
            if(G[u][v]!=0&&queue[v]==1&&key[v]>G[u][v])
            {
                parent[v]=u;
                key[v]=G[u][v];
            }

    }
    return tcost;
}
void main(){
int V=5;
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    printf("Edges selected:\n");
    printf("\nTotal weight:%d",prim(V,graph,0));
 
}
