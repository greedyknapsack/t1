#include<stdio.h>

#include<stdlib.h>

int comp(void const*a,void const*b)
{
    const int (*t1)[3]=a;
    const int (*t2)[3]=b;
    return (1.0*(*t1)[1]/(*t1)[0])<(1.0*(*t2)[1]/(*t2)[0]);
}
float knapsack(int n,int item[n][3],int m,float vector[n])
{
    float p=0;
    qsort(item,n,sizeof(item[0]),comp);
    for(int i=0;i<n;i++)
    {
        
        if(m>=item[i][0])
        {
            m-=item[i][0];
            vector[item[i][2]]=1;
            p+=item[i][1];
        }
        else
        {
            p+=(1.0*m/item[i][0]*item[i][1]);
            vector[item[i][2]]=1.0*m/item[i][0];
            m=0;
        }
    }
    return p;
}
void main()
{
    int n,m;
    printf("Enter the number of items:");
    scanf("%d",&n);
    printf("Enter knapsack size:");
    scanf("%d",&m);
    int it[n][3];
    float v[n];
    printf("Enter weight and profit sequentially:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&it[i][0],&it[i][1]);
        it[i][2]=i;
    }
    printf("Total profit:%lf\nSoln vector:",knapsack(n,it,m,v));
    for(int i=0;i<n;i++)
        printf("%lf ",v[i]);
}
