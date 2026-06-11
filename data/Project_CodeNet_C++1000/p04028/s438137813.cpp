#include <cstring>
#include <cstdio>
constexpr int MOD = 1e9 + 7;
int dp[5005][5005];
char str[5005];
int main()
{
	// freopen("ARC059-F.in", "r", stdin);
	int n;
	scanf("%d%s", &n, str);
	int m = strlen(str);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			(dp[i + 1][j + 1] += dp[i][j]) %= MOD;
			(dp[i + 1][j + 1] += dp[i][j]) %= MOD;
			(dp[i + 1][j ? j - 1 : 0] += dp[i][j]) %= MOD;
		}
	}
	long long ans = dp[n][m];
	for (int i = 0; i < m; i++)
		ans = ans * (MOD + 1) / 2 % MOD;
	printf("%lld\n", ans);
	return 0;
}
