#include<cstdio>
#include<cstring>
typedef long long ll;
const int MAXN = 5000;
const int MOD = int(1E9) + 7;
char s[MAXN + 5];
ll dp[MAXN + 5][MAXN + 5];
int main() {
	int N;
	scanf("%d", &N);
	scanf("%s", s+1);
	int len = strlen(s+1);
	dp[0][0] = 1;
	for(int i=1;i<=N;i++) {
		dp[i][0] = (dp[i-1][0] + 2LL * dp[i-1][1]) % MOD;
		for(int j=1;j<=i;j++)
			dp[i][j] = (2LL * dp[i-1][j+1] + dp[i-1][j-1]) % MOD;
	}
	printf("%lld\n", dp[N][len]);
}