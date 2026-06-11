#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
const int mod = 1e9+7;
int n, k, dp[maxn+10][maxn+10], sum[maxn*maxn+10];
int powe(int base, int p) {
	int res = 1;
	for (; p; p >>= 1, base = 1ll*base*base%mod)
		if (p&1) res = 1ll*res*base%mod;
	return res;
}
int C(int n, int m) {
	int k = 1ll*sum[m]*sum[n-m]%mod;
	return 1ll*sum[n]*powe(k, mod-2)%mod;
}
int main() {
	scanf("%d%d", &n, &k);
	sum[0] = 1;
	for (int i = 1; i <= n*k; ++i) 
		sum[i] = 1ll*sum[i-1]*i%mod;
	if (k == 1) {
		printf("%d\n", 1); return 0;
	}
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			dp[i][j] = (dp[i-1][j]+1ll*dp[i][j-1]*C(n*k-i-(j-1)*(k-1)-1, k-2))%mod;
	printf("%d\n", 1ll*dp[n][n]*sum[n]%mod);
	return 0;
}