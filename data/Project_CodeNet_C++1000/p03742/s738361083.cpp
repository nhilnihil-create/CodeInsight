#include<bits/stdc++.h>
using namespace std;
int p[200][200];
main()
{
	int m,n;
    scanf("%d%d",&m,&n);
    if(abs(m-n)<=1)
    printf("Brown");
    else
    printf("Alice");
    // for(int is = 0;is <= 30;is++)
    // {
    //     for(int j = is;j >= 0;j--)
    //     {
    //         int i=is-j;
    //         int ck=0;
    //         if(i==2 && j==0)
    //         {}
    //         printf("%d %d\n",i,j);
    //         if(i <= 1 && j <= 1 && (i!=j || j==0))
    //         {
    //             //printf("%d %d\n",i,j);
    //             p[i][j]=1;
    //             continue;
    //         }
    //         else
    //         {
    //             for(int ii = 1;ii*2 <= i;ii++)
    //             {
    //                 ck=max(ck,p[i-2*ii][j+ii]);
    //             }
    //             for(int jj = 1;jj*2 <= j;jj++)
    //             {
    //                 //if(i==2 && j==0)
    //                 //printf("%d %d\n")
    //                 ck=max(ck,p[i+jj][j-2*jj]);
    //             }
    //         }
    //         if(ck==0)
    //         p[i][j]=1;
    //         else
    //         p[i][j]=0;
    //     }
    // }
    // for(int i = 0;i <= 30;i++)
    // {
    //     for(int j = 0;j <= 30;j++)
    //     {
    //         if(p[i][j]==1)
    //         printf("P ");
    //         else
    //         printf("N ");
    //     }
    //     printf("\n");
    // }
}
