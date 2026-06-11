#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MOD 1000000007

int mpow(int a, int b) {
	int res = 1;
	for (int cur = a; b; b >>= 1) {
		if (b & 1) res = (int64_t) res * cur % MOD;
		cur = (int64_t) cur * cur % MOD;
	}
	return res;
}

int dp[5001][5001]; // i times => j

int main() {
	int n;
	scanf("%d", &n);
	char s[5001];
	scanf("%s", s);
	
	int k = strlen(s);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// add 0/1
			dp[i + 1][j + 1] += 2 * dp[i][j] % MOD;
			if (dp[i + 1][j + 1] >= MOD)
				dp[i + 1][j + 1] -= MOD;
			// remove
			if (j) {
				dp[i + 1][j - 1] += dp[i][j];
				if (dp[i + 1][j - 1] >= MOD)
					dp[i + 1][j - 1] -= MOD;
			} else {
				dp[i + 1][j] += dp[i][j];
				if (dp[i + 1][j] >= MOD)
					dp[i + 1][j] -= MOD;
			}
		}
	}
	printf("%d", (int)((int64_t) dp[n][k] * mpow(mpow(2, k), MOD - 2) % MOD));
	
	
	
	return 0;
}
