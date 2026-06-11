#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=5e3+20;
ll n,m;
string s;
ll dp[N][N];
ll powmod(ll x,ll n) {
    ll s=1;
    while(n) {
        if(n&1)
            s=(s*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return s;
}
int main() {
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0; i<=5000; i++) {
        for(int j=0; j<=5000; j++) {
            if(dp[i][j]==0) continue;
            dp[i+1][j+1]=(dp[i+1][j+1]+(2ll*dp[i][j])%mod)%mod;
            (dp[i+1][max(0,j-1)]+=dp[i][j]%mod)%=mod;
        }
    }
    while(cin>>n>>s) {
        ll l=s.length();
        ll ans=dp[n][l];
        ll t=powmod(2ll,l);
        ans=(ans*powmod(t,mod-2))%mod;
        cout<<ans<<endl;
    }
    return 0;
}