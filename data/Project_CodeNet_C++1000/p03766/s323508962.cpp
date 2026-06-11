#include <cstdio>

const int mod = 1e9 + 7, maxn = 1e6 + 10;

int n, ans, f[maxn], g[maxn], sum[maxn];

int main() {
	scanf("%d", &n);
	f[n] = n - 1;
	g[n] = n;
	sum[n] = n;
	for (int i = n - 1; i; --i) {
		f[i] = (1ll * (n - 1) * (n - 1) + sum[i + 3] + (i == n - 1 ? n - 1 : i + 1)) % mod;
		g[i] = (f[i] + g[i + 1]) % mod;
		sum[i] = (sum[i + 1] + g[i]) % mod;
	}
	printf("%d\n", g[1]);
	return 0;
}