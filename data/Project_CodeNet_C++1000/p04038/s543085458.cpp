#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
int n, k, jc[4000010], ny[4000010];
int f[2010][2010];
inline int ksm (int a, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod, p >>= 1;
	}
	return res;
}
inline int C (int n, int m) { return 1ll * jc[n] * ny[m] % mod * ny[n - m] % mod; }
int main () {
	scanf ("%d%d", &n, &k);
	if (k == 1) { printf ("1\n"); return 0; }
	jc[0] = 1; for (int i = 1; i <= 4000000; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
	ny[4000000] = ksm (jc[4000000], mod - 2);
	for (int i = 4000000; i >= 1; i--) ny[i - 1] = 1ll * ny[i] * i % mod;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			(f[i + 1][j] += f[i][j]) %= mod;
			int x = n * k - j * k - i + j;
			(f[i][j + 1] += 1ll * f[i][j] * C (x - 1, k - 2) % mod) %= mod;
		}
		(f[i + 1][i] += f[i][i]) %= mod;
	}
	for (int i = 1; i <= n; i++) f[n][n] = 1ll * f[n][n] * i % mod;
	printf ("%d\n", f[n][n]);
	return 0;
}