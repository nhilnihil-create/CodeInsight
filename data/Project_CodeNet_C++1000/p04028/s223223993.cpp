#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int maxm = maxn*2;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll qpow(ll a,ll b,ll p){
    ll ret = 1; if(p==1) return 0; if(b==0) return 1;
    while(b){if(b&1) ret = (ret*a) % p; a = (a*a) % p;b>>=1;}
    return ret;
}
char s[5005];
int n;
ll dp[5005][5005];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>(s+1);
    dp[0][0] = 1;
    for(int i = 0;i<=n;i++) {
        for(int j = 0;j<=i;j++){
            dp[i+1][j+1] = (dp[i+1][j+1] + 2*dp[i][j]%mod) % mod;
            dp[i+1][max(j-1,0)] = (dp[i+1][max(j-1,0)] + dp[i][j]) % mod;
        }
    }
    cout<<dp[n][strlen(s+1)]*qpow(qpow(2,strlen(s+1),mod),mod-2,mod)%mod;
}
