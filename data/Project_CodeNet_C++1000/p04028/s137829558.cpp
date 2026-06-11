#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=5000+5;
const int mod=1e9+7;
ll dp[maxn][maxn];
inline ll fastpow(ll a,ll b) {
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}
int main() {
    int n,k;cin>>n;string s;cin>>s;k=s.length();
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
    	dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
    	for(int j=1;j<=i;j++) {
    		dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1]*2)%mod;
    	}
    }
    cout<<dp[n][k]*fastpow(fastpow(2,k),mod-2)%mod<<endl;
    return 0;
}