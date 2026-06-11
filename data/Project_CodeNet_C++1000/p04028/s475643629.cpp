#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll _pow(ll a, ll n) {
	if(n==0) return 1;
	else {
		ll res = 1;
		ll buf = a;
		while(n>0) {
			if(n%2==1) {
				res *= buf;
				res %= MOD;
			}
			buf *= buf;
			buf %= MOD;
			n/=2;
		}
		return res;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	string s;
	cin>>n>>s;
	vector<vector<ll>> dp(n+1,vector<ll>(5001,0));
	dp[0][0]=1;
	FOR(i,1,n+1) REP(j,5001) {
		if(j==0) dp[i][j]+=dp[i-1][j];
		if(j>0) dp[i][j]+=2*dp[i-1][j-1];
		if(j<5000)dp[i][j]+=dp[i-1][j+1];
		dp[i][j]%=MOD;
	}
	ll tmp=_pow(2,(ll)s.size());
	tmp=_pow(tmp,MOD-2);
	cout<<(dp[n][(ll)s.size()]*tmp)%MOD<<endl;
	return 0;
}
