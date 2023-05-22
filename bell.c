#include<stdio.h>

int bell(int V,int E,int G[V][V],int w[E][3],int s)
{
    int d[V],p[V];
    for(int i=0;i<E;i++)
        {
            d[i]=9999;
            p[i]=-1;
        }
    d[s]=0;
    for(int i=0;i<V-1;i++)
    {
        for(int e=0;e<E;e++)
            if(d[w[e][1]]>d[w[e][0]]+w[e][2])
                {
                    d[w[e][1]]=d[w[e][0]]+w[e][2];
                    p[w[e][1]]=w[e][0];
                }
    }
    for(int i=0;i<V;i++)
        printf("%d\t", d[i]);
    for(int e=0;e<E;e++)
        if(d[w[e][1]]>d[w[e][0]]+w[e][2])
            return 1;
    return 0;
    
}

void main()
{
    int V=5,E=0;
    int w[V*(V-1)/2][3];
    int graph[5][5] = { { 0, 6, 7, 0, 0 },
                        { 0, 0, 8, 5, -4 },
                        { 0, 0, 0, -3, 9 },
                        { 0, -2, 0, 0, 0 },
                        { 0, 0, 0, 7, 0 } };
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            if(graph[i][j]!=0&&i!=j)
                {
                    w[E][0]=i;
                    w[E][1]=j;
                    w[E++][2]=graph[i][j];
                }
        }

    printf("\nNegative cycle is %s present\n",bell(V,E,graph,w,0)?"":"not");
    
}
