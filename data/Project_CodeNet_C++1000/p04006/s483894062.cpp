#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int a[N],x,n,mn[N];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mn[i]=1e9+1;
    ll ans=1e18;
    for(int i=0;i<n;i++)
    {
        ll sum=1ll*i*x;
        for(int j=1;j<=n;j++)
        {
            mn[j]=min(mn[j],a[(j+i-1)%n+1]);
            sum+=mn[j];
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
