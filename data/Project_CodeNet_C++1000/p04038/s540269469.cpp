#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 2005;
const ll MOD = 1000000007;

int n,k;

ll fac[MAXN * MAXN];
ll inv[MAXN * MAXN];
ll f[MAXN][MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n * k;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n * k] = power(fac[n * k],MOD - 2);
	for (int i = n * k;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	cin >> n >> k;
	if (k == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	init();
	f[0][0] = 1;
	for (int i = 1;i <= n;i++)
		f[0][i] = f[0][i - 1] * C((k - 1) * i - 1,k - 2) % MOD;
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
		{
			f[i][j] = f[i - 1][j];
			if (i < j)
				(f[i][j] += f[i][j - 1] * C((k - 1) * j + i - 1,k - 2)) %= MOD;
		}
	cout << f[n][n] * fac[n] % MOD << endl;
	return 0;
}