#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2010;
const int MOD = 1e9 + 7;

int n, K, f[N][N];
int fac[N*N], rev[N*N];

int quick_pow(int x, int times)
{
	if(x == 0) return 0;
	int ans = 1, mult = x;

	while(times)
	{
		if(times & 1)
			ans *= mult, ans %= MOD;
		mult *= mult, mult %= MOD, times >>= 1;
	}
	return ans;
}

void init()
{
	fac[0] = fac[1] = 1;
	for(register int k = 2; k <= n * K; k++)
		fac[k] = fac[k - 1] * k % MOD;

	rev[n * K] = quick_pow(fac[n * K], MOD - 2);
	for(register int k = n * K - 1; k >= 0; k--)
		rev[k] = (rev[k + 1] * (k + 1)) % MOD;
}

int C(int up, int down)
{
	return ((fac[down] * rev[up] % MOD) * rev[down - up]) % MOD;
}

signed main()
{
	scanf("%lld %lld", &n, &K), init();
	if(K == 1)
	{
		printf("1");
		return 0;
	}

	f[0][0] = 1;
	for(register int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
		{
			f[i][j] += f[i - 1][j];
			if(j - 1 >= 0)
				f[i][j] += (f[i][j - 1] * (n - j + 1) % MOD) * C(K - 2, n * K - i - (j - 1) * (K - 1) - 1) % MOD, f[i][j] %= MOD;
		}

	printf("%lld", f[n][n]);

	return 0;
}