#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a,b,p[maxn],l,Q;
int f[maxn][35];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&p[i]);
    scanf("%d",&l);
    for (int i=1;i<=n;i++)
     {
        int idx=upper_bound(p+1,p+1+n,p[i]+l)-p-1;
        if(p[i]+l>=p[n]) f[i][0]=n;
        else f[i][0]=idx;
    }
    for (int j=1; j<=30; j++)
        for (int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        int cur=a,ans=0;
        for (int i=30; i>=0; i--)
        {
            if(f[cur][i]<b)
            {
                ans+=(1<<i);
                cur = f[cur][i];
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}