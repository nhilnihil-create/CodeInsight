//waz
#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))
 
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;
 
#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))
 
int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

const int mod = 1e9 + 7;

int fpow(int a, int x)
{
	int ret = 1;
	for (; x; x >>= 1)
	{
		if (x & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
	}
	return ret;
}

int f[2010][2010], n, k, fac[2010 * 2010], ifac[2010 * 2010];

int C(int n, int m)
{
	if (n < m || m < 0) return 0;
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int get(int x, int y)
{
	return C(x + y, y);
}

int main()
{
	gii(n, k);
	if (k == 1)
	{
		puts("1");
		return 0;
	}
	f[0][0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= (n + 2) * (k + 2); ++i) fac[i] = 1LL * fac[i - 1] * i % mod;
	ifac[(n + 2) * (k + 2)] = fpow(fac[(n + 2) * (k + 2)], mod - 2);
	for (int i = (n + 2) * (k + 2); i; --i) ifac[i - 1] = 1LL * ifac[i] * i % mod;
	for (int i = 0; i <= n; ++i)
		for (int j = i; j <= n; ++j)
		{
			
			if (i) f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
			if (j) f[i][j] = (f[i][j] + 1LL * f[i][j - 1] * get((j - 1) * (k - 1) + i, k - 2)) % mod;
			//cerr << "get = " << get(j * (k - 1), k - 2) << endl;
		}
	printf("%d\n", int((1LL * f[n][n] * fac[n]) % mod));
	return 0;
}