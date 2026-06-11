#include<bits/stdc++.h>
using namespace std;
#define llong long long
int n,m;
int nu[100100];
llong sum[100100];
int main()
{
    scanf("%d%d",&n,&m);
    llong ans=0;
    for(int i=1;i<=n;++i)
        scanf("%d",&nu[i]);
    for(int i=2;i<=n;++i)
    {
        if(nu[i]>=nu[i-1])
        {
            ans+=nu[i]-nu[i-1];
            sum[nu[i-1]+2]++;
            sum[nu[i]+1]--;
        }
        else
        {
            ans+=nu[i]+m-nu[i-1];
            sum[nu[i-1]+2]++;
            sum[m+1]--;
            sum[0]+=m-nu[i-1]-1;
            sum[1]++;
            sum[nu[i]+1]--;
        }
    }
    for(int i=2;i<=m;++i)sum[i]+=sum[i-1];
    for(int i=2;i<=n;++i)
        if(nu[i]>=nu[i-1])
            sum[nu[i]+1]-=nu[i]-nu[i-1]-1;
        else sum[nu[i]+1]-=nu[i]+m-nu[i-1]-1;
    llong ma=0;
    for(int i=1;i<=m;++i)
    {
        sum[i]+=sum[i-1];
        ma=max(ma,sum[i]);
    }
    ans-=ma;
    printf("%lld\n",ans);
    return 0;
}
