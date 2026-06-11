#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

const int MAXN = 2e3 + 10, MAXL = 4e6 + 10;

int n, m, L;
int dp[MAXN][MAXN], fac[MAXL], inv[MAXL];

int C(int n, int m) {
	if (n < m) return 0;
	return (long long)fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	scanf("%d%d", &n, &m);
	if (m <= 1) {
		puts("1");
		return 0;
	}
	L = n * m;
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= L; ++i) {
		fac[i] = (long long)fac[i - 1] * i % mod;
		inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= L; ++i)
		inv[i] = (long long)inv[i - 1] * inv[i] % mod;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = i; ~j; --j) {
			dp[i][j] = dp[i][j + 1]; // put white
			if (j) (dp[i][j] += (long long)dp[i - 1][j - 1] * C(i * m - j - 1, m - 2) % mod) %= mod;
		}
	printf("%d\n", static_cast<int>((long long)dp[n][0] * fac[n] % mod));
}