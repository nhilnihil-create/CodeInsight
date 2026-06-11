#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll dp[5001][5001];
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			(dp[i + 1][j + 1] += dp[i][j] * 2) %= MOD;
			(dp[i + 1][max(j - 1, 0)] += dp[i][j]) %= MOD;
		}
	}
	ll ans = dp[N][s.size()];
	ll x = mod_pow(2, MOD - 2);
	(ans *= mod_pow(x, s.size())) %= MOD;
	cout << ans << endl;
}
