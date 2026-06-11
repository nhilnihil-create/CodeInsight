#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005, mod = 1e9 + 7;

int n, k;
int f[maxN + 1][maxN + 1];
int fac[maxN * maxN + 1], inv[maxN * maxN + 1];

inline int ADD(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }

inline int mpow(int a, int x)
{
	int ans = 1;
	while(x)
	{
		if(x & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		x >>= 1;
	}
	return ans;
}

inline int C(int n, int m)
{
	if(n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	scanf("%d %d", &n, &k);
	if(k == 1) { puts("1"); return 0; }
	
	fac[0] = 1;
	for(int i = 1; i <= n * k; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n * k] = mpow(fac[n * k], mod - 2);
	for(int i = n * k - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;

	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
		{
			if(j) f[i][j] = f[i][j - 1];
			f[i][j] = ADD(f[i][j], 1ll * f[i - 1][j] * C(i * (k - 1) + j - 1, k - 2) % mod);
		}

	int ans = 1ll * f[n][n] * fac[n] % mod;
	printf("%d", ans);
	return 0;
}