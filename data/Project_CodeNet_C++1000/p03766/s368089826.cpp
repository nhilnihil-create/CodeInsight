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
typedef pair<pll, pll> P;
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

ll n;
ll dp[1123456];

int main() {
	cin >> n;
	
	dp[n] = 1;
	dp[n - 1] = n;
	dp[n - 2] = n * n % MOD;
	
	ll sum = dp[n];
	for (int i = n - 3; i >= 0; i--) {
		dp[i] += dp[i + 1]; // 1
		dp[i] += (n - 1) * (n - 1) % MOD; // (a>1) (b>1)
		dp[i] += sum + n - 1 - (n - 3 - i + 1); // (a>1) 1^(a)
		dp[i] %= MOD;
		
		sum = (sum + dp[i + 2]) % MOD;
	}
	cout << dp[0] << endl;
	
	return 0;
}
