#include <bits/stdc++.h>
#define rep(i,s,t) for (int i=s;i<=t;++i)
#define fi first
#define se second
const int maxn=4e6+10;
const int mod=1e9+7;
typedef long long ll;
using namespace std;
ll quick_mod(ll x,ll y){
    ll ans=1;
    for (;y;y>>=1){
        if (y&1) ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}
ll fac[maxn],inv[maxn],ans;
ll dp[2010][2010];
void init(){
    fac[0]=1;
    rep(i,1,maxn-10) fac[i]=fac[i-1]*i%mod;
    inv[maxn-10]=quick_mod(fac[maxn-10],mod-2);
    for (int i=maxn-11;i>=0;--i){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll c(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    init();
    int n,k; scanf("%d%d",&n,&k);
    if (k==1) return 0*puts("1");
    dp[0][0]=1;
    rep(i,0,n){
        rep(j,0,n){
            if (i) (dp[i][j]+=dp[i-1][j])%=mod;
            if (j>i) (dp[i][j]+=dp[i][j-1]*c(i+j*(k-1)-1,k-2)%mod)%=mod;
        }
    }
    printf("%lld\n",fac[n]*dp[n][n]%mod);
    return 0;
}
