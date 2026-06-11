#include <bits/stdc++.h>
using namespace std;

const int
	MAX = 5005,
	MOD = 1e9 + 7;
int n, m, dp[MAX][2 * MAX];
char a[MAX];

int exp(int a, int b) {
	if(b == 0)
		return 1;

	if(b & 1)
		return 1LL * a * exp(a, b - 1) % MOD;

	int sq = exp(a, b / 2);
	return 1LL * sq * sq % MOD;
}

int F(int i, int c) {
	if(c < 0)
		return 0;

	if(i == n)
		return c == m;

	int &ans = dp[i][c];

	if(ans != -1)
		return ans;

	ans = 2LL * F(i + 1, c + 1) % MOD;

	if(c == 0)
		ans = (ans + F(i + 1, 0)) % MOD;

	else ans = (ans + F(i + 1, c - 1)) % MOD;

	return ans;
}

int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);

	m = strlen(a + 1);

	memset(dp, -1, sizeof(dp));

	int inv = exp(2, MOD - 2);
	int ans = 1LL * F(0, 0) * exp(inv, m) % MOD;

	printf("%d\n", ans);
	return 0;
}