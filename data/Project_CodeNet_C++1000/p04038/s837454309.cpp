#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e6 + 5, Mod = 1e9 + 7;

int n, k;
ll p[N], inv[N], P[N];

ll Pow(ll x, ll y) {
	ll cur = 1;
	while (y) {
		if (y & 1) cur = cur * x % Mod;
		x = x * x % Mod;
		y >>= 1;
	}
	return cur;
}

void Pre() {
	p[0] = 1; for (int i = 1; i < N; ++ i) p[i] = p[i - 1] * (ll)i % Mod;
	inv[N - 1] = Pow(p[N - 1], Mod - 2);
	for (int i = N - 2; i >= 0; -- i) inv[i] = inv[i + 1] * (ll)(i + 1) % Mod;
}

ll Calc(int x, int y) {
	return p[x] * inv[x - y] % Mod * inv[y] % Mod;
}

void Mul(ll &x, ll y) {
	x *= y; x %= Mod;
}

ll f[2005][2005];

int main(void) {
	Pre();
	scanf("%d%d", &n, &k);
	if (k == 1) return 0 * puts("1");

	f[0][1] = 1;
	for (int i = 2; i <= n; ++ i) {
		f[0][i] = f[0][i - 1] * Calc(i*(k-1)-1, k - 2) % Mod;	
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = i; j <= n; ++ j) {
			f[i][j] = f[i][j - 1] * Calc(i + j * (k - 1) - 1, k - 2) % Mod;
			if (f[i][j] >= Mod) f[i][j] -= Mod;
			f[i][j] += f[i - 1][j];
			if (f[i][j] >= Mod) f[i][j] -= Mod;
		}
	}
	printf("%lld\n", f[n][n] * p[n] % Mod);
	return 0;
} 