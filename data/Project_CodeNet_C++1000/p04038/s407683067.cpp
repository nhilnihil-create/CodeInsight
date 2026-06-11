#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mod = 1000000007;
int n, m;
long long fact[N * N], invfact[N * N], dp[N][N];
long long C(int x, int y) {
	if (x < y) return 0;
	return fact[x] * invfact[y] % mod * invfact[x - y] % mod;
}
int main() {
	scanf("%d%d", &n, &m);
	if (m == 1) {puts("1"); return 0;}
	invfact[1] = 1;
	for (int i = 2; i <= n * m; i++)
		invfact[i] = (mod - mod / i) * invfact[mod % i] % mod;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= n * m; i++)
		fact[i] = fact[i - 1] * i % mod, invfact[i] = invfact[i - 1] * invfact[i] % mod;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!i && !j) continue;
			if (i) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = 0;
			if (j) dp[i][j] = (dp[i][j] + dp[i][j - 1] * C(i + j * (m - 1) - 1, m - 2)) % mod;
		}
	}
	printf("%lld\n", dp[n][n] * fact[n] % mod);
	return 0;
}