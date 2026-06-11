#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e3 + 10;
const int MOD = 1e9 + 7;
 
long long dp[MAXN][MAXN];
long long fac[MAXN * MAXN];
int n, k;
 
// asdjgfsadjkgfjksdgjfka
// sadjkgfasjdgfjasdgfjgasdgfaskjdf
// asdjgfajsdgfjasgdfgasdkjfgsadgfkjasdgfkjasdgfksadgf
#define fsgdfjasgdfgsadkjfg asdkjgfkjsagdfsgadjfgasdkjfaksjdf
#define hdgfhadfhasdhfgasjdgfjadgsjfkgsajdfgsadhjgfjksgadfj jsdgfjkasdgjfksgadkjfa
#define hafsdhfashfh ashdfshgadfadsjhgfashgdfshgadfshadfjshgadfj
int fsdgasdjkfjajksadgfkjags = 213213123;
long long fdashf = 13243543;

long long po(long long v, long long u)
{
	return u ? (po(v * v % MOD, u >> 1) * (u & 1 ? v : 1) % MOD) : 1;
}
 
long long ente(int i, int j)
{
	long long res = po(fac[i], MOD - 2) * po(fac[j - i], MOD - 2);
	res %= MOD;
	res *= fac[j];
	return res % MOD;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i < MAXN * MAXN; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	if (k == 1)
		return cout << 1 << '\n', 0;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i)
				dp[i][j] = dp[i - 1][j];
			if (j)
				dp[i][j] += dp[i][j - 1] * ente(k - 2, i + j * (k - 1) - 1);
			dp[i][j] %= MOD;
		}
	}
	dp[n][n] = (dp[n][n] * fac[n]) % MOD;
	cout << dp[n][n] << '\n';
	return 0;
}