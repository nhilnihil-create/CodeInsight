#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int n;
ll tmp, ans; 
ll f[maxn], g[maxn];
void norm(ll & x) 
{ 
	while(x < 0) x += mod; 
	while(x >= mod) x -= mod;
}
int main()
{
	scanf("%d", &n);
	f[0] = f[1] = 1;
	g[0] = 1;
	g[1] = 2;
	for(int i = 2; i <= n; ++i)
	{
		f[i] = g[i - 1] - f[i - 2];
		g[i] = g[i - 1] + f[i];
		norm(f[i]);
		norm(g[i]);
	}
	for(int i = 0; i <= n; ++i)
	{
		ll tmp = 0;
		if(i <= n - 2)
			tmp = (tmp + 1ll * (n - 1) * (n - 1) % mod) % mod;
		if(i <= n - 1)
			tmp = (tmp + min(n - 1, i + 1)) % mod;
		if(i == n)
			tmp = 1;
		ans = (ans + tmp * f[i] % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}
	