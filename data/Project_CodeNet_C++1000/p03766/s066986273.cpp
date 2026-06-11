#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
long long ans,sum,f[1000005],g[1000005];int n;
int main()
{
    scanf("%d",&n);f[1]=1;
    for(int i=1;i<=n;i++) (f[i]+=i>=3?g[i-3]:0)%=P,(f[i]+=f[i-1])%=P,(g[i]=g[i-1]+f[i])%=P;
    for(int i=1;i<n;i++) (ans+=1ll*f[i]*(n-1)%P*(n-1)%P)%P;
    for(int i=1;i<n-1;i++) (ans+=1ll*f[i]*(i+1)%P)%P;
    (ans+=1ll*f[n]*n%P)%=P;(ans+=1ll*f[n-1]*(n-1)%P)%=P;printf("%d\n",ans);
}