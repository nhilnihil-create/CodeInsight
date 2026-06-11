#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll dp[5005][5005];

ll modpow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {		
		for (int j = 0; j <= i; j++) {
			(dp[i + 1][j + 1] += dp[i][j] * 2) %= MOD;
			(dp[i + 1][max(j - 1, 0)] += dp[i][j]) %= MOD;
		}
	}

	int m = s.length();
	ll ans = dp[n][m];
	ans = ans * modpow(modpow(2, m), MOD - 2) % MOD;
	cout << ans << endl;
	return 0;
}