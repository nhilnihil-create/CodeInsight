#include <iostream>
using namespace std;

const int MAXN = 2005, MOD = 1e9 + 7;
long long f[MAXN * MAXN];
long long dp[MAXN][MAXN], n, k;
long long rev(long long a) {
	int b = MOD - 2;
	long long res = 1;
	for (b; b; b /= 2) {
		if (b % 2)
			res *= a, res %= MOD;
		a *= a, a %= MOD;
	}
	return res;
}
long long ch(int a, int b) {
	return f[a] * rev(f[b]) % MOD * rev(f[a - b]) % MOD;
}

int main() {
	cin >> n >> k;
	if (k == 1)
		return cout << 1, 0;
	f[0] = 1;
	for (int i = 1; i < MAXN * MAXN; i++)
		f[i] = f[i - 1] * i, f[i] %= MOD;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			dp[i][j] = dp[i - 1][j] * ch(n * k - j - (i - 1) * (k - 1) - 1, k - 2) + dp[i][j - 1], dp[i][j] %= MOD;
	cout << f[n] * dp[n][n] % MOD;
}