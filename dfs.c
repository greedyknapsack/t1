#include<stdio.h>
int *color,*d,*p,*f,time;
void dfs_visit(int V,int G[V][V],int u)
{
    printf("%d %d %d\t",u,p[u],time);
    color[u]=-1;//grey
    d[u]=++time;
    for(int v=0;v<V;v++)
        if(G[u][v]!=0&&color[v]==1)
        {
            p[v]=u;
            dfs_visit(V,G,v);
        }
    f[u]=++time;
    color[u]=0;//black
}
void dfs(int V,int G[V][V])
{
    time=0;
    int c[V],dt[V],pt[V],ft[V];
    color=c;p=pt;f=ft;
    d=dt;
    for(int i=0;i<V;i++)
    {
        p[i]=-1;
        color[i]=1;
    }
    for(int v=0;v<V;v++)
        if(color[v]==1)
            dfs_visit(V,G,v);
}
void main()
{
    int g[5][5] = {
    {0,0,1,0,1},
    {0,0,0,1,1},
    {1,0,0,1,0},
    {0,1,1,0,0},
    {1,1,0,0,0}};
    dfs(5,g);
}
