#include <bits/stdc++.h>

using namespace std;

const int maxn = 4010;
const int mod = 1e9+7;

int n, k;
int dp[maxn][maxn], fac[2000*2000+10], ifac[2000*2000+10], inv[2000*2000+10];

int binom(int x, int y) {
	if (y > x) return 0;
	return 1LL * fac[x] * ifac[y] % mod * ifac[x-y] % mod;
}

int main() {
	scanf("%d%d", &n, &k);
	if (k == 1){
		puts("1");
		return 0;
	}
	fac[0] = ifac[0] = 1; inv[1] = 1;
	for (int i = 2; i <= n*k; i++) inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
	for (int i = 1; i <= n*k; i++) fac[i] = 1LL * fac[i-1] * i % mod, ifac[i] = 1LL * ifac[i-1] * inv[i] % mod;
	dp[0][0] = 1;
	for (int i = 1; i <= 2*n; i++) {
		for (int j = i&1; (i+j) <= 2*n; j+=2) {
			// j = ( - )
			// )
			if (j < n) {
				dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
			}
			// (
			if (j > 0) {
				dp[i][j] = (dp[i][j] + 1LL * binom((k-2)*((j+i)/2)+i-1, k-2) * dp[i-1][j-1] % mod) % mod;
			}
		}
	}
	printf("%d\n", int (1LL * dp[2 * n][0] * fac[n] % mod));
	return 0;
}