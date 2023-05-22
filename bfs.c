#include<stdio.h>
void bfs(int V,int G[V][V],int s)
{
    int d[V],p[V],color[V],queue[V],f=-1,r=-1;
    for(int i=0;i<V;i++)
    {
        d[i]=9999;
        p[i]=-1;
        color[i]=1;//White
    }
    d[s]=0;
    color[s]=-1;//Grey
    queue[f=r=0]=s;
    while(f!=V)
    {
        int u=queue[f++];
        color[u]=0;//Black
        printf("%d\t",u);
        for(int v=0;v<V;v++)
        {
            if(G[u][v]!=0&&color[v]==1)
            {
                color[v]=-1;
                queue[++r]=v;
                d[v]=d[u]+1;
                p[v]=u;
            }
        }
    }
}
void main()
{
    int g[5][5] = {
    {0,0,1,0,1},
    {0,0,0,1,1},
    {1,0,0,1,0},
    {0,1,1,0,0},
    {1,1,0,0,0}};
    bfs(5,g,0);
}
