#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int MaxN(2003);
const int MaxL(4000003);
const int Mod(1e9 + 7);

int F[MaxN][MaxN];
int fac[MaxL], rfac[MaxL];

int fexp(int x, int k)
{
	int res = 1;
	for(; k; k >>= 1, x = (ull) x * x % Mod)
		if(k & 1) res = (ull) res * x % Mod;
	return res;
}

inline int C(int n, int m)
{
	return n < m ? 0 : (ull) fac[n] * rfac[m] % Mod * rfac[n - m] % Mod;
}

int main()
{
	int n, K;
#ifdef zxp
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	if(K == 1) return puts("1"), 0;
	for(int i = fac[0] = 1; i <= n * K; i++)
		fac[i] = (ull) fac[i - 1] * i % Mod;
	rfac[n * K] = fexp(fac[n * K], Mod - 2);
	for(int i = n * K; i; i--)
		rfac[i - 1] = (ull) rfac[i] * i % Mod;
	F[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
		{
			F[i][j] = F[i - 1][j];
			if(j) F[i][j] = (F[i][j] + (ull) (n - j + 1) * C((K - 1) * (n - j + 1) + n - i - 1, K - 2) % Mod * F[i][j - 1]) % Mod;
		}
	printf("%d\n", F[n][n]);
	return 0;
}
