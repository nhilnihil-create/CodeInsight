#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = (long long)(1e9 + 7);
const int kK = (int)(2049 * 2049);

long long fac[kK + 5], inv[kK + 5];

long long qpow(long long base,int power)
{
	long long ret = 1;
	for(; power; power >>= 1)
	{
		if(power & 1) ret = ret * base % MOD;
		base = base * base % MOD;
	}
	return ret;
}

inline long long C(int x, int y)
{
	return(((fac[y] * inv[x]) % MOD) * inv[y - x]) % MOD;
}

int n, k;
long long f[2049][2049];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(k == 1)
	{
		cout << 1 <<endl;
		return 0;
	}
	fac[0] = 1;
	for(int i = 1; i <= kK; ++i) fac[i] = fac[i-1] * i % MOD;
	inv[kK] = qpow(fac[kK], MOD - 2);
	for(int i = kK; i >= 1; --i) inv[i - 1] = inv[i] * i % MOD;
	f[0][0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		f[i][0] = f[i - 1][0];
		for(int j = 1; j <= i; ++j)
		{
			f[i][j] = f[i - 1][j];
			f[i][j] = f[i][j] + f[i][j - 1] * C(k - 2, n * k - i - (j - 1)*(k - 1) - 1);
			f[i][j] %= MOD;
		}
	}
	cout << fac[n] * f[n][n] % MOD<<endl;
	
	return 0;
}