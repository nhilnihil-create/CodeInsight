#include <cstdio>
typedef long long ll;
const int N = 2e3 + 5;
const int A = 4e6 + 6;
const int Mod = 1e9 + 7;
int n, m, Ax, g[N][N], fac[A], Ifac[A];
inline int pow(int x, int k) {
	ll res = 1, r = x;
	for (; k; k >>= 1, (r *= r) %= Mod)
		if (k & 1) (res *= r) %= Mod;
	return res;
}
inline int calc(int n, int m) {
	return (ll)fac[n] * Ifac[m] % Mod * Ifac[n - m] % Mod;
}
int main() {
	scanf("%d%d", &n, &m);
	if (m == 1) {
		puts("1");
		return 0;
	}
	
	Ax = n * m, fac[0] = 1;
	for (int i = 1; i <= Ax; ++i) fac[i] = (ll)fac[i - 1] * i % Mod;
	
	Ifac[Ax] = pow(fac[Ax], Mod - 2);
	for (int i = Ax; i; --i) Ifac[i - 1] = (ll)Ifac[i] * i % Mod;
			
	g[0][0] = 1;
	for (int k = 1; k <= n; ++k) {
		g[k][0] = (g[k - 1][0] + g[k - 1][1]) % Mod;
		for (int i = 1; i + k <= n; ++i) (g[k][i] = g[k][i - 1] + g[k - 1][i + 1]) %= Mod;
		
		for (int i = 0; i + k <= n; ++i) {
			int ret = Ax - (k - 1) * m - i - 2;
			g[k][i] = (ll)g[k][i] * calc(ret, m - 2) % Mod;
		}
	}
	printf("%lld\n", (ll)g[n][0] * fac[n] % Mod);
}