#include<bits/stdc++.h>
using namespace std;
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while (!isdigit(t) && t != '-') t = getchar();
	if (t == '-')
	{
		_read(x);
		x *= -1;
		return ;
	}
	while (isdigit(t))
		x = x * 10 + t - '0', t = getchar();
} 
const int MAXN = 2005, MAXM = 2000 * 2000 + 1e5 + 5, mo = 1e9 + 7;
int n, k, f[MAXN][MAXN], fac[MAXM], invfac[MAXM];
inline int C(int n, int m)
{
	return 1ll * fac[n] * invfac[m] % mo * invfac[n - m] % mo;
}
int main()
{
	_read(n), _read(k);
	invfac[0] = fac[0] = fac[1] = invfac[1] = 1;
	if(k == 1)return puts("1"), 0;
	for(int i = 2; i <= MAXM - 5; ++i)fac[i] = 1ll * fac[i - 1] * i % mo, invfac[i] = 1ll * (mo - mo / i) * invfac[mo % i] % mo;
	for(int i = 2; i <= MAXM - 5; ++i)invfac[i] = 1ll * invfac[i] * invfac[i - 1] % mo;
	f[1][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
		{
			if(i ^ j)(f[i][j + 1] += f[i][j] %= mo);
			if(i ^ n)(f[i + 1][j] += 1ll * f[i][j] * C((k - 2) + (i * (k - 1) + j), k - 2) % mo) %= mo;
		}
	cout << 1ll * f[n][n]*fac[n] % mo;
	return 0;
}