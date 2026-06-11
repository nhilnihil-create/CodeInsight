#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long s64;

const int ONE = 2005;
const int MOD = 1e9 + 7;

int get()
{
		int res = 1, Q = 1; char c;
		while( (c = getchar()) < 48 || c > 57)
			if(c == '-') Q = -1;
		if(Q) res = c - 48;
		while( (c = getchar()) >= 48 && c <= 57)
			res = res * 10 + c - 48;
		return res * Q;
}

int Qucikpow(int a, int b)
{
		int res = 1;
		while(b)
		{
			if(b & 1) res = (s64)res * a % MOD;
			a = (s64)a * a % MOD;
			b >>= 1;
		}
		return res;
}

int n, k;
int fac[ONE * ONE], inv[ONE * ONE];

void Deal_first()
{
		fac[0] = 1;
		for(int i = 1; i <= n * k; i++)
			fac[i] = (s64)fac[i - 1] * i % MOD;

		inv[n * k] = Qucikpow(fac[n * k], MOD - 2);
		for(int i = n * k; i >= 1; i--)
			inv[i - 1] = (s64)inv[i] * i % MOD;
}

int C(int n, int m)
{
		return (s64)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int f[ONE][ONE];

int main()
{
		//freopen(".in","r",stdin);
		//freopen(".out","w",stdout);
		n = get(), k = get();
		if(k == 1) {printf("1\n"); return 0;}
		Deal_first();

		f[1][1] = f[1][0] = 1;
		for(int i = 2; i <= n; i++)
			for(int j = 0; j <= i; j++)
			{
				if(j) (f[i][j] += f[i][j - 1]) %= MOD;
				(f[i][j] += (s64)f[i - 1][j] * C(i * (k - 1) + j - 1, k - 2) % MOD) %= MOD;
			}

		printf("%d", (s64)f[n][n] * fac[n] % MOD);
}