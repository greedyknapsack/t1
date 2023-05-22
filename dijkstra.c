#include<stdio.h>
int extractmin(int V,int *q,int *d)
{
    int r=-1;
    for(int v=0;v<V;v++)
        if(q[v]&&(r==-1||d[r]>d[v]))
            r=v;
    q[r]=0;
    return r;
}
int dijkstra(int V,int G[V][V],int s)
{
    int q[V],d[V],p[V],count=V,tcost=0;
    for(int v=0;v<V;v++)
    {
        d[v]=9999;
        p[v]=-1;
        q[v]=1;
    }
    d[s]=0;
    printf("Vertex selected in order:\n");
    while(count)
    {
        int u=extractmin(V,q,d);
        tcost+=d[u];
        printf("%d ",u);//Adding to the solution
        for(int v=0;v<V;v++)
            if(G[u][v]!=0&&d[v]>d[u]+G[u][v])
            {
                d[v]=d[u]+G[u][v];
                p[v]=u;
            }
        count--;
    }
    return tcost;
}
void main()
{
    
    int V=5;
    int graph[5][5] = { { 0, 10, 5, 0, 0 },
                        { 0, 0, 2, 1, 0 },
                        { 0, 3, 0, 9, 2 },
                        { 0, 0, 0, 0, 4 },
                        { 0, 0, 0, 6, 0 } };
    
    // Print the solution
   
    printf("\nTotal cost:%d",dijkstra(V,graph,0));
}
