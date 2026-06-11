#pragma GCC optimize(3) 
#include <cstdio>
const int N = 2010;
const int mod = 1e9 + 7;
int n, k, fac[N * N], inv[N * N], f[N][N];
inline int C(int x, int y) {
	return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main() {
	scanf("%d%d", &n, &k);
	if (k == 1) {
		puts("1");
		return 0;
	}
	fac[0] = fac[1] = 1; for (int i = 2; i <= n * k; ++ i) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[0] = inv[1] = 1; for (int i = 2; i <= n * k; ++ i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n * k; ++ i) inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
	for (int i = 0; i <= n; ++ i) f[i][0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j) {
			f[i][j] = (f[i - 1][j] + (1ll * f[i][j - 1] * (n - j + 1) % mod * C(n - i + (n - j + 1) * (k - 1) - 1, k - 2) % mod)) % mod;
		}
	printf("%d\n", f[n][n]);
	return 0;
}