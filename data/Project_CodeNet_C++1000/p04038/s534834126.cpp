#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 2005;
const int mod = 1e9 + 7;
LL n , k;
LL fac[MAXN * MAXN] , inv[MAXN * MAXN] , finv[MAXN * MAXN];
LL C(LL a , LL b) {
	if(a == 0 || b == 0 || a == b) return 1;
	return fac[a] * finv[a - b] % mod * finv[b] % mod;
}
LL dp[MAXN][MAXN];
int main() {
	scanf("%lld %lld" , &n , &k);
	if(k == 1) {
		printf("1");
		return 0;
	}
	fac[0] = 1;
	for (LL i = 1; i <= n * k; ++i) fac[i] = fac[i - 1] * i % mod;
	finv[1] = inv[1] = 1;
	for (LL i = 2; i <= n * k; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod , finv[i] = finv[i - 1] * inv[i] % mod;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if(j) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] * C(n * k - (k - 1) * (j - 1) - i - 1 , k - 2) % mod) % mod;
			else dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%lld" , dp[n][n] * fac[n] % mod);
	return 0;
}