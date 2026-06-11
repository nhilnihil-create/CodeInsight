#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][MAXN];
string shit;

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0][0]=1;
	for (int i=1; i+1<MAXN; i++){
		dp[i][0]=(dp[i-1][0] + dp[i-1][1])%mod;
		for (int j=1; j<=i; j++)
			dp[i][j]=(dp[i-1][j-1]*2 + dp[i-1][j+1])%mod;
	}
	
	cin>>n>>shit;
	m=shit.size();
	ans=dp[n][m];
	ans=ans*powmod(2, mod-1-m)%mod;
	cout<<ans<<"\n";
	
	return 0;
}
