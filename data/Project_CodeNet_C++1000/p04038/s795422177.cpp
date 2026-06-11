#include<bits/stdc++.h>

using namespace std;

const int N = 2010;
const int mod = 1e9 + 7;

int fac[N * N], inv[N * N], f[N][N];

int qpow(int a, int x) {
	int ret = 1;
	while(x) {
		if(x & 1) ret = (long long)ret * a % mod;
		x >>= 1, a = (long long)a * a % mod;
	}
	return ret;
}

int C(int n, int m) {
	if(n < m || n < 0 || m < 0) return 0;
	return (long long)fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void Init(int n) {
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= n; ++ i)
		fac[i] = (long long)fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for(int i = n; i >= 1; -- i)
		inv[i - 1] = (long long)inv[i] * i % mod;
}

int main() {
#ifdef ylsakioi
	freopen("agc002f.in", "r", stdin);
	freopen("agc002f.out", "w", stdout);
#endif
	int n, k;
	Init(N * N - 10);
	scanf("%d%d", &n, &k);
	if(k == 1) return puts("1"), 0;
	f[1][0] = 1;
	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= i; ++ j) {
			if(i) (f[i][j] += f[i - 1][j]) %= mod;
			if(j) (f[i][j] += 1ll * C((n - j + 1) * (k - 1) + (n - i) - 1, k - 2) * f[i][j - 1] % mod) %= mod;
		}
	printf("%d\n", (long long)f[n][n] * fac[n] % mod);
	return 0;
}
