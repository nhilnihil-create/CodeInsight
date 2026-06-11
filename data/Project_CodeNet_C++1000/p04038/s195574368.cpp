#include <bits/stdc++.h>

const int mod = 1000000007, N = 2005;
typedef long long LL;

int n, k, f[N * N], inv[N * N], dp[N][N];
int pow(int x, int y, int ans = 1) {
	for (; y; y >>= 1, x = (LL) x * x % mod)
		if (y & 1) ans = (LL) ans * x % mod;
	return ans;
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> k;
	if (k == 1) return std::cout << 1 << '\n', 0;
	f[k - 2] = 1, inv[1] = 1;
	for (int i = 2; i <= n * k - (k - 2); ++i)
		inv[i] = (LL) inv[mod % i] * (mod - mod / i) % mod;
	for (int i = k - 1; i <= n * k; ++i)
		f[i] = (LL) f[i - 1] * i % mod * pow(i - (k - 2), mod - 2) % mod;
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			dp[i][j] = (dp[i - 1][j] + (LL) dp[i][j - 1] * f[n * k - i - (j - 1) * (k - 1) - 1]) % mod;
	}
	int ans = dp[n][n];
	for (int i = 1; i <= n; ++i) ans = (LL) ans * i % mod;
	std::cout << ans << '\n';
	return 0;
}