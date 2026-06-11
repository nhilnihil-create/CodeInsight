#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

ll dp[2][5001];
int n;
string s;

ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}

int main() {
	cin >> n >> s;
	
	int size = s.size();
	
	dp[0][0] = 1;
	REP(i, n) {
		memset(dp[(i + 1) & 1], 0, sizeof(dp[0]));
		
		REP(j, i + 1) {
			(dp[(i + 1) & 1][max(j - 1, 0)] += dp[i & 1][j]) %= MOD;
			(dp[(i + 1) & 1][j + 1] += dp[i & 1][j] * 2) %= MOD;
		}
	}
	
	ll ans = dp[n & 1][size];
	ans = ans * mod_pow(mod_pow(2, size, MOD), MOD - 2, MOD) % MOD;
	
	cout << ans << endl;
	
	return 0;
}
