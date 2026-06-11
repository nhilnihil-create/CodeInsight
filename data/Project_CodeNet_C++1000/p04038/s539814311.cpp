#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll dp[2010][2010] , jc[5000010];
ll Pow(ll x , ll y)
{
	ll res = 1;
	while (y)
	{
		if (y & 1)
		{
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return res;
}
ll getc(int n , int r)
{
	return (jc[n] * Pow(jc[n - r] * jc[r] % mod , mod - 2)) % mod;
}
int main()
{
	int n , k;
	scanf("%d%d" , &n , &k);
	jc[0] = 1;
	for (int i = 1; i <= 5000000; i++)
	{
		jc[i] = (jc[i - 1] * i) % mod;
	}
	if (k == 1)
	{
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += dp[i][j - 1] * (n - j + 1) % mod
			* getc((n - j + 1) * (k - 1) + n - i - 1 , k - 2) % mod;
			dp[i][j] %= mod;
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	printf("%lld\n" , dp[n][n]);
	return 0;
}