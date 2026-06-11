#include <iostream>
#include <cstdio>

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

int n, sum;
int dp[MAXN + 2];

int main() {
	scanf("%d", &n);
	dp[n] = n;
	dp[n - 1] = 1LL * n * n % MOD;
	for (int i = n - 2; i >= 1; --i) {
		sum = (sum + dp[i + 3]) % MOD;
		dp[i] = (1LL * dp[i] + dp[i + 1] + sum + i + 1 + (n - 1) * 1LL * (n - 1)) % MOD;
	}
	printf("%d\n", dp[1]);
	return 0;
}
