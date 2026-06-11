#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100006;
int a[maxn];
int f[maxn][36];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int l;
    scanf("%d",&l);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    {
        int id=(int)(upper_bound(a+1,a+n+1,a[i]+l)-a-1);
        f[i][0]=id;
    }
    for(int j=1;j<=30;j++)
    {
        for(int i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    while(q--)
    {
        int bx,by;
        scanf("%d%d",&bx,&by);
        if(bx>by)swap(bx,by);
        int sum=0;
        int x=bx;
        for(int i=30;i>=0;i--)
        {
            if(f[x][i]<by)
            {
                sum+=(1<<i);
                x=f[x][i];
            }
        }
        printf("%d\n",sum+1);
    }
    return 0;

}
/*
9
1 3 6 13 15 18 19 29 31
10
6
1 2
1
1 4
*/
