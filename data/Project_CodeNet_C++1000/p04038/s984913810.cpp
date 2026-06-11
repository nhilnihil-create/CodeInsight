#include<bits/stdc++.h>

using namespace std;

#define N 2005
const int mod = 1000000007;
#define add(x, y) (x + y >= mod ? x + y - mod : x + y)
#define dec(x, y) (x < y ? x - y + mod : x - y)

int Pow(int x, int k)
{
	int ans = 1, base = x;
	while(k)
	{
		if(k & 1) ans = 1ll * ans * base % mod;
		base = 1ll * base * base % mod;
		k >>= 1;
	}
	return ans;
}

int n, k, f[N][N], pw[N * N], inv[N * N];

int C(int x, int y)
{
	return 1ll * pw[y] * inv[y - x] % mod * inv[x] % mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	pw[0] = inv[0] = 1;
	for(int i = 1; i <= n * k; i++) pw[i] = 1ll * pw[i - 1] * i % mod, inv[i] = Pow(pw[i], mod - 2);
	if(k == 1) {cout << 1 << endl; return 0;}
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			f[i][j] = add(f[i - 1][j], (1ll * f[i][j - 1] * (n - j + 1) % mod * C(k - 2, n * k - i - (j - 1) * (k - 1) - 1) % mod));
		}
	}
	printf("%d\n", f[n][n]);
	return 0;
}