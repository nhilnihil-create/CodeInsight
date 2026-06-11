// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e3+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll n,k,dp[maxn][maxn],fac[maxn*maxn],inv[maxn*maxn];
ll pwm(ll a,ll b){
	if(b==0) return 1;
	if(b%2) return a*pwm(a,b-1)%mod;
	ll ret=pwm(a,b/2);
	return ret*ret%mod;
}
ll C(ll n,ll r){return fac[n]*inv[r]%mod*inv[n-r]%mod;}
void add(ll &x,ll y){x+=y;if(x>=mod)x-=mod;}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	if(k==1) return cout<<1,0;
	fac[0]=inv[0]=1; for(int i=1;i<maxn*maxn;i++) fac[i]=fac[i-1]*i%mod, inv[i]=pwm(fac[i],mod-2);
	dp[0][0]=1;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++){
		add(dp[i+1][j],dp[i][j]);
		if(j<i) add(dp[i][j+1],dp[i][j]*C(n*k-i-j*(k-1)-1,k-2)%mod);
	}
	cout<<dp[n][n]*fac[n]%mod;
	
	return 0;
}




