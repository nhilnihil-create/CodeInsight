#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

const int MOD = 1e9 + 7;
i64 mod_pow(i64 x, i64 n = MOD - 2) {
	i64 ret = 1;
	
	while(n) {
		if(n & 1) (ret *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	
	return ret;
}

int main() {
	int n; cin >> n;
	std::string s; cin >> s;
	
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1, 0)); dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i + 1][std::max(0, j - 1)] += dp[i][j];
			dp[i + 1][j + 1] += dp[i][j] * 2;
			
			dp[i + 1][std::max(0, j - 1)] %= MOD;
			dp[i + 1][j + 1] %= MOD;
		}
	}
	
	cout << dp[n][s.size()] * mod_pow(mod_pow(2, s.size())) % MOD << endl;
	return 0;
}
