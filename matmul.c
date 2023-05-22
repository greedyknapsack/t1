#include<limits.h>
#include<stdio.h>
void print(int n,int a[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%10d \t",a[i][j]);
        printf("\n");
    }
}

void mul(int n,int m[n][n],int s[n][n],int p[n])
{
    int t;
    for(int i=0;i<n;i++)
        m[i][i]=0;

    for(int l=2;l<n;l++)
        for(int i=1;i<n-l+1;i++)
        {
            
            int j=i+l-1;
            m[i][j]=99999999;
            printf("%d %d %d\n",l,i,j);
            for(int k=i;k<j;k++)
                {
                    printf("%d %d %d\n",l,i,k);
                    t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(m[i][j]>t)
                    {
                        m[i][j]=t;
                        s[i][j]=k;
                        
                    }
                }

        }
}
/*
void mul(int n,int m[n][n],int s[n][n],int d[n])
{
    int q=0;
    for(int i=0;i<n;i++)
        m[i][i]=0;
   
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            //printf("%d %d\n",l,i);
            int j=i+l-1;
            m[i][j]=999999999;

            for(int k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                if(m[i][j]>q)
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }


}
*/
void braces(int V,int s[V][V],int i,int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        braces(V,s,i,s[i][j]);
        braces(V,s,s[i][j]+1,j);
        printf(")");
    }
}



void main()
{
    int n=4;
    int d[]={1,2,3,4};
    int t[n][n],s[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
        t[i][j]=-1;
        s[i][j]=-1;
        }
    mul(n,t,s,d);
    print(n,t);
    print(n,s);
    braces(n,s,1,n-1);
}
