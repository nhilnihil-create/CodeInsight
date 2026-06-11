#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
int x[maxn], y[maxn];
ll sufx, sufy, h, w;
void norm(ll & x)
{
	while(x < 0) x += mod;
	while(x >= mod) x -= mod;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for(int i = n; i; --i)
	{
		sufx += x[i]; 
		norm(sufx);
		w += sufx - 1ll * x[i] * (n - i + 1) % mod;
		norm(w);
	}
	for(int i = 1; i <= m; ++i)
		scanf("%d", &y[i]);
	for(int i = m; i; --i)
	{
		sufy += y[i];
		norm(sufy);
		h += sufy - 1ll * y[i] * (m - i + 1) % mod;
		norm(h);
	}
	cout << h * w % mod << endl;
	return 0;
}