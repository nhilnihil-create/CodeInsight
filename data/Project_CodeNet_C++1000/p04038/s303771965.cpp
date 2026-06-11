#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 2005
#define M 4000005
void Add(int &x,int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}
int n, k, m, f[N][N];
int fac[M], inv[M];
int C(int n, int m){return (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;}
int Pow(int a, int k)
{
	int ret = 1;
	while (k)
	{
		if (k & 1)
			ret = (ll)ret * a % mod;
		a = (ll)a * a % mod;
		k >>= 1;
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	m = n * k;
	if (k == 1)
	{
		puts("1");
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= m; i++)
		fac[i] = (ll)fac[i - 1] * i % mod;
	inv[m] = Pow(fac[m], mod - 2);
	for (int i = m; i >= 1; i--)
		inv[i - 1] = (ll)inv[i] * i % mod;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++)
		{
			Add(f[i][j], f[i - 1][j]);
			if(j)
				Add(f[i][j], (ll)f[i][j - 1] * (n - j + 1) % mod * C((n - i) + (n - j + 1) * (k - 1) - 1, k - 2) % mod);
		}
	printf("%d\n", f[n][n]);
}
