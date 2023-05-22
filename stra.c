#include<stdio.h>
#include<math.h>
void imat(int nn,int A[nn][nn],int n)
{
    for(int i=0;i<nn;i++)
    for(int j=0;j<nn;j++)
    if(i<n&&j<n)
        scanf("%d",&A[i][j]);
    else
        A[i][j]=0;
}
void smul(int n,int A[n][n],int B[n][n],int C[n][n])
{
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }
    
    int nn=n/2,a[nn][nn],b[nn][nn],c[nn][nn],d[nn][nn];
    int e[nn][nn],f[nn][nn],g[nn][nn],h[nn][nn];
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++)
        {
            
            a[i][j]=A[i][j];
            b[i][j]=A[i][nn+j];
            c[i][j]=A[nn+i][j];
            d[i][j]=A[nn+i][nn+j];
            e[i][j]=B[i][j];
            f[i][j]=B[i][nn+j];
            g[i][j]=B[nn+i][j];
            h[i][j]=B[nn+i][nn+j];
        }
    
    int s1[nn][nn],s2[nn][nn],s3[nn][nn],s4[nn][nn],s5[nn][nn];
    int s6[nn][nn],s7[nn][nn],s8[nn][nn],s9[nn][nn],s10[nn][nn];
    
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++)
        {
            s1[i][j]=f[i][j]-h[i][j];
            s2[i][j]=a[i][j]+b[i][j];
            s3[i][j]=c[i][j]+d[i][j];
            s4[i][j]=g[i][j]-e[i][j];
            s5[i][j]=a[i][j]+d[i][j];
            s6[i][j]=e[i][j]+h[i][j];
            s7[i][j]=b[i][j]-d[i][j];
            s8[i][j]=g[i][j]+h[i][j];
            s9[i][j]=a[i][j]-c[i][j];
            s10[i][j]=e[i][j]+f[i][j];
        }
    int p1[nn][nn],p2[nn][nn],p3[nn][nn],p4[nn][nn];
    int p5[nn][nn],p6[nn][nn],p7[nn][nn];
    smul(nn,a,s1,p1);
    smul(nn,s2,h,p2);
    smul(nn,s3,e,p3);
    smul(nn,d,s4,p4);
    smul(nn,s5,s6,p5);
    smul(nn,s7,s8,p6);
    smul(nn,s9,s10,p7);
    
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++)
            {
                C[i][j]=p5[i][j]+p6[i][j]+p4[i][j]-p2[i][j];
                C[i][nn+j]=p1[i][j]+p2[i][j];
                C[nn+i][j]=p3[i][j]+p4[i][j];
                C[nn+i][nn+j]=p1[i][j]-p3[i][j]+p5[i][j]-p7[i][j];
            }
}
void main()
{
   int n;
    printf("Enter order:");
    scanf("%d",&n);
    int nn=pow(2,ceil(log2(n)));

    printf("%d\n",nn);
    int A[nn][nn],B[nn][nn],C[nn][nn];
    printf("Enter the 1st matrix:\n");
    imat(nn,A,n);
    printf("Enter the 2nd matrix:\n");
    imat(nn,B,n);
    imat(nn,C,0);
   /*
    int n=4;
    int A[4][4] = 
    {{1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};
    int B[4][4] = 
    {{1, 0, 0, 0},
    {0, 1, 1, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};
    int C[4][4]=
    {{0, 0, 0, 0},
    {0, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}};
    */
    smul(nn,A,B,C);
    printf("Solution:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
}
