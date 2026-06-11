#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int i2 = (MOD + 1) / 2;
const int MAXN = 5010;
int N, M;
char S[MAXN];
int dp[MAXN][MAXN];

// let dp[i][j] be the number of ways to make a string of length j using i operations
// it's obvious that the number of ways to form each string of length j is equal
// we only need to divide dp[N][|S|] by 2^|S| to get the answer

int main() {
	scanf("%d %s", &N, S); M = int(strlen(S));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i+1][j+1] = (dp[i+1][j+1] + ll(2) * dp[i][j]) % MOD;
			dp[i+1][max(j-1, 0)] = (dp[i+1][max(j-1, 0)] + dp[i][j]) % MOD;
		}
	}

	int ans = dp[N][M];
	for (int i = 0; i < M; i++) ans = ll(ans) * i2 % MOD;
	printf("%d\n", ans);

	return 0;
}