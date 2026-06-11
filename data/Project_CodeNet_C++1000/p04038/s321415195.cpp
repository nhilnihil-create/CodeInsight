#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
const int mo = 1e9 + 7;
using namespace std;
typedef long long ll;
ll fpm(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mo;
		a = a * a % mo;
		b >>= 1; 
	}
	return res;
}
const int MAXN = 2e3 + 10;
const int MAXV = 4e6 + 10;
ll fac[MAXV], facinv[MAXV];
int n, k;
inline void pre()
{
	fac[0] = 1;
	for (register int i = 1; i <= n * k; ++i) fac[i] = 1ll * i * fac[i - 1] % mo;
	facinv[n * k] = fpm(fac[n * k], mo - 2);
	for (register int i = n * k; i > 0; --i) facinv[i - 1] = 1ll * facinv[i] * i % mo;
	 
}
template <class T> 
inline ll binom(T a, T b)
{
	if (a - b < 0) return 0;
	if (b < 0) return 0;
	return fac[a] * facinv[b] % mo * facinv[a - b] % mo;
}
ll f[MAXN][MAXN];
int main(int argc, char **argv)
{
	cin >> n >> k;
	if (k == 1) return puts("1"), 0; 
	pre();
	f[0][0] = 1;
	for (register int i = 1; i <= n; ++i)
	{
		for (register int j = 0; j <= i; ++j)
		{
			f[i][j] = f[i - 1][j];
			if (!j) continue;
			f[i][j] = (f[i][j] + f[i][j - 1] * (n - j + 1) % mo * binom(n - i + (n - j + 1) * (k - 1) - 1, k - 2) % mo) % mo; 
		}
	}
	cout << f[n][n] << endl;
	return 0;
}