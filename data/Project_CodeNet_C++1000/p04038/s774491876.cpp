#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MOD = 1e9 + 7;
inline int qpow(int a, int b)
{
	register int res = 1;
	for(; b; b >>= 1)
	{
		if(b & 1)
			res = (long long)res * a % MOD;
		a = (long long)a * a % MOD;
	}
	return res;
}
int f[MAXN][MAXN];
int fac[MAXN * MAXN], fav[MAXN * MAXN];
int n, k;
inline int C(int n, int m)
{
	return (long long)fac[n] * fav[m] % MOD * fav[n - m] % MOD;
}
int main()
{
	cin >> n >> k;
	if(k == 1)
	{
		puts("1");
		return 0;
	}
	fac[0] = 1;
	for(register int i = 1; i <= n * k; ++i)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	fav[n * k] = qpow(fac[n * k], MOD - 2);
	for(register int i = n * k - 1; i >= 0; --i)
		fav[i] = (long long)fav[i + 1] * (i + 1) % MOD;
	f[0][0] = 1;
	for(register int i = 1; i <= n; ++i)
	{
		for(register int j = 0; j <= i; ++j)
		{
			f[i][j] = f[i - 1][j];
			if(j)
				f[i][j] = (f[i][j] + (long long)f[i][j - 1] * (n - j + 1) % MOD * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % MOD) % MOD;
//			cerr << f[i][j - 1] << " ";
		}
//		cerr << endl;
	}
	cout << f[n][n] << endl;
} 