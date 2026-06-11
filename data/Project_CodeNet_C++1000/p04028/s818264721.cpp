#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

char s[5005];
long long dp[5005][5005];

void add(long long &x, long long y) {
	x = (x + y) % MOD;
}

int main() {
	int n;
	scanf("%d%s", &n, s + 1);
	
	int l = strlen(s + 1);
	
	dp[0][0] = 1LL;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j + 1 <= l) add(dp[i][j], 2LL * dp[i - 1][j + 1]);
			else add(dp[i][j], dp[i - 1][j + 1]);
			
			if (j <= l) {
				if (j == 0) add(dp[i][j], dp[i - 1][j]);
				else add(dp[i][j], dp[i - 1][j - 1]);
			}
			else {
				add(dp[i][j], 2LL * dp[i - 1][j - 1]);
			}
		}
	}
	
	printf("%lld\n", dp[n][l]);
}
