#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;
//ａをbで割る
long long mod_div(long long a,long long b){
	if(a % b == 0)return a/b;
	long long tmp = MOD - 2,c = b,ret = 1;
	while(tmp > 0){
		if(tmp & 1){
			ret *= c;ret %= MOD;
		}
		c *= c;c %= MOD;tmp >>= 1;
	}
	return a*ret%MOD;
}

#define MAX_K 2222*2222
vector<long long> kaijo(MAX_K);
long long combination(long long n, long long r){
    if(n < r || n < 0 || r < 0)
        return 0;
	if(kaijo[0] != 1){
		kaijo[0] = 1;
		for(long long i = 1;i < MAX_K;i++)kaijo[i] = (kaijo[i-1] * i) % MOD;
	}
    long long ret = kaijo[n];
	long long tmp = (kaijo[r] * kaijo[n-r]) % MOD;
    return mod_div(ret,tmp);
}

ll dp[2222][2222];

ll n,k;
ll dfs(ll a,ll b){
	if(dp[a][b] != -1){
		return dp[a][b];
	}
	ll ret = 0;
	if(a > 0){
		ret += dfs(a - 1, b);
		ret %= MOD;
	}
	if(b > a){
		ret += combination(a + b * (k - 1) - 1,k - 2) * dfs(a, b - 1) % MOD;
		ret %= MOD;
	}
	return dp[a][b] = ret;
}

int main(){

	REP(i,2222)REP(j,2222)dp[i][j] = -1;

	dp[0][0] = 1;
	cin >> n >> k;
	if(k == 1){
		cout << 1 << endl;
	}
	else{
		ll ans = 1;
		for(ll i = 1;i <= n;i++)ans = (ans * i) % MOD;
		cout << dfs(n,n)*ans%MOD << endl;
	}

	return 0;
}
