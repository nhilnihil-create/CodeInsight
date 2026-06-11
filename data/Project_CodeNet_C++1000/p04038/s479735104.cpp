// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e3+10;
const ll mod=1e9+7;
const ll maxn2=4e6+20;

#pragma GCC Optimize("Ofast")

ll dp[maxn][maxn];
ll cnk[maxn2],fac[maxn2],inv[maxn2],ifac[maxn2];
ll N,K;
	
ll pw(ll a, ll b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }

void prep(){
	fac[0]=ifac[0]=inv[1]=1;
	FOR(i,1,maxn2-1)
		fac[i]=(i*fac[i - 1])%mod;
	FOR(i,2,maxn2-1) 
		inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
	FOR(i,1,maxn2-1)
		ifac[i] =(inv[i]*ifac[i-1])%mod;
	FOR(i,(K-2),maxn2-1)
		cnk[i]=(((fac[i]*ifac[K-2])%mod)*ifac[i-K+2])%mod;
}

int main(){
	cin>>N>>K;
	if(K==1){
		cout<<1;
		return 0;
	}
	prep();
	
	dp[1][0]=dp[1][1]=1;
	FOR(i,2,N){
		FORD(j,i,1){
			dp[i][j]=(i*((cnk[(i*K)-j-1]*dp[i-1][j-1])%mod))%mod;
			dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
		}
		dp[i][0]=dp[i][1];
	}
	cout<<dp[N][0];
}