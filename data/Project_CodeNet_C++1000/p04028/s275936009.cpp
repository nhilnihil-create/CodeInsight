#include <cstdio>
const int mod = 1000000007;
const int inv2 = 500000004;
int n, m, dp[5009][5009]; char s[5009];
int main() {
	scanf("%d %s", &n, s); while (s[m]) m++; dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j + 1] + (j != 0 ? dp[i - 1][j - 1] >= inv2 ? dp[i - 1][j - 1] * 2 - mod : dp[i - 1][j - 1] * 2 : dp[i - 1][0]);
			if (dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}
	for (int i = 0; i < m; i++) dp[n][m] = 1LL * dp[n][m] * inv2 % mod;
	printf("%d\n", dp[n][m]);
	return 0;
}