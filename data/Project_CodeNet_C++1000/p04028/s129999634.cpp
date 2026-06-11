#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;
const ll mod = 1e9 + 7;
char s[maxn];
ll f[maxn][maxn], tmp[maxn], ret[maxn], h[maxn];
int n, m;
void add(ll & x, const ll y)
{
	x += y;
	if(x >= mod) x -= mod;
}
void calc(ll * ret, ll * a, ll * b)
{
	memset(tmp, 0, sizeof tmp);
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
			add(tmp[i], a[i - j] * b[j] % mod);
	for(int i = 0; i <= n; ++i) ret[i] = tmp[i]; 
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	m = strlen(s + 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
		{
			if(j) add(f[i][j], f[i - 1][j - 1] * 2 % mod);
			add(f[i][j], f[i - 1][j + 1]);
		}
	for(int i = 0; i <= n; ++i) h[i] = f[i][0];
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
		{
			if(j) add(f[i][j], f[i - 1][j - 1] * 2 % mod);
			else add(f[i][j], f[i - 1][j]);
			add(f[i][j], f[i - 1][j + 1]);
		}
	for(int i = 0; i <= n; ++i) ret[i] = f[i][0];
	int k = m;
	while(k)
	{
		if(k & 1) calc(ret, ret, h);
		calc(h, h, h); k >>= 1;
	}
	printf("%lld\n", ret[n - m]);
	return 0;
}
	