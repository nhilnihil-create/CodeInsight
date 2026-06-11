#include <bits/stdc++.h>

const int N = 5005, mod = 1000000007;

void reduce(int &x) { x += x >> 31 & mod; }
int dp[N][N], n, l; std::string s;

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> s, l = s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 2u) % mod;
			reduce(dp[i + 1][std::max(j - 1, 0)] += dp[i][j] - mod);
		}
	}
	int ans = dp[n][l]; while (l--) ans = ans * (mod + 1LL >> 1) % mod;
	std::cout << ans << '\n';
	return 0;
}