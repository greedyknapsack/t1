#include<stdio.h>
#include<stdlib.h>
int findparent(int *p,int i)
{
    while(p[i]>=0)
        i=p[i];
    return i;
}
void findunion(int *p,int i,int j)
{
    if(p[i]<p[j])
    {
        p[i]+=p[j];
        p[j]=i;
    }
    else
    {
        p[j]+=p[i];
        p[i]=j;
    }
}
int compare(const void*t1,const void*t2)
{
    const int (*a)[3]=t1;
    const int (*b)[3]=t2;
    return (*a)[2]-(*b)[2]; 
}
int kruskal(int V,int E,int G[V][V],int w[E][3],int A[E][3])
{
    int p[V];
    for(int v=0;v<V;v++)
        p[v]=-1;
    
    qsort(w,E,sizeof(w[0]),compare);

    int tcost=0,e=0,ecount=0;
    while(e<E&&ecount<V-1)
    {
        for(int i=0;i<V;i++)
            printf("%d ",p[i]);
        printf("\n");
        if(findparent(p,w[e][0])!=findparent(p,w[e][1]))
            {
                findunion(p,w[e][0],w[e][1]);
                A[ecount][0]=w[e][0];
                A[ecount][1]=w[e][1];
                A[ecount++][2]=w[e][2];
                tcost+=w[e][2];
            }
        e++;
    }
    return tcost;
}

void main()
{
	   /*
	int nv,ne=0,ec=0;
    printf("Enter number of vertices:");
    scanf("%d",&nv);
    printf("Enter number of edges:");
    scanf("%d",&ne);
    int g[nv][nv];
	int w[nv*(nv-1)][3];
	int A[nv-1][3];
    printf("Enter the adjacency matrix:\n");
	

	
    for(int i=0;i<nv;i++)
        for(int j=0;j<nv;j++)
		{
            scanf("%d",&g[i][j]);
			if(i<j&&g[i][j]!=0)
			{
				w[ne][0]=i;
				w[ne][1]=j;
				w[ne++][2]=g[i][j];
			}
		}
	
	*/
	
	int nv=4,ne=6,ec=0;
	int w[6][3] = { { 0, 1, 10 },
                       { 0, 2, 6 },
                       { 0, 3, 5 },
                       { 1, 3, 15 },
                       { 2, 3, 4 },
					   {3,1,1} };
	int A[nv-1][3];
	
    printf("Total weight: %d\n",kruskal(nv,ne,NULL,w,A));
	printf("The edges included:\nEdge\tWeight");
	for(int i=0;i<nv-1;i++)
		printf("\n%d - %d\t%d",A[i][0],A[i][1],A[i][2]);
}
