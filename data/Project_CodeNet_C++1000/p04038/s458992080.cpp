#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e3 + 10;
const int Mod = 1e9 + 7;

void Chkadd(int &x, const int &y) { if ((x += y) >= Mod) x -= Mod; }

int Power(int a, int k)
{
	int x = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) x = 1ll * x * a % Mod;
		a = 1ll * a * a % Mod;
	}
	return x;
}

int fac[maxn * maxn], inv[maxn * maxn];

void Prepare_fac(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i)
		fac[i] = 1ll * fac[i - 1] * i % Mod;
	inv[n] = Power(fac[n], Mod - 2);
	for (int i = n; i; -- i)
		inv[i - 1] = 1ll * inv[i] * i % Mod;
}

int C(int n, int m)
{
	if (n < 0 || n < m || m < 0) return 0;
	return 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int f[maxn][maxn];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	Prepare_fac(n * k);
	if (k == 1)
	{
		puts("1");
		return 0;
	}
	f[0][0] = 1;
	for (int i = 0; i <= n; ++ i)
	{
		if (i) f[i][i] = f[i - 1][i];
		for (int j = i + 1; j <= n; ++ j)
		{
			f[i][j] = 1ll * f[i][j - 1] * C(i + j * (k - 1) - 1, k - 2) % Mod;
			if (i) Chkadd(f[i][j], f[i - 1][j]);
		}
	}
	printf("%lld\n", 1ll * f[n][n] * fac[n] % Mod);
	return 0;
}
