#include<bits/stdc++.h>
 
using namespace std;
const int N=2000+10;
typedef long long ll;
const ll llf=(1ll<<63)-1;
ll dp[N][N],a[N];
int main()
{
    int n;
    ll x,ans=llf;
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        dp[0][i]=a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ind=j-i;
            if(ind<=0)  ind=n+ind;
            dp[i][j]=min(dp[i-1][j],a[ind]);
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        ll ant=0;
        for(int j=1;j<=n;j++)
            ant+=dp[i][j];
        ans=min(ans,ant+i*x);
       // cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}