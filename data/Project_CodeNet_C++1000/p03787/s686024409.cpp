//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20;
int n, m;
vector <int> g[N];

int cnt[3];

int flag;
int d[N];
bool vis[N];

ll ans;

void dfs (int v)
{
	vis[v] = 1;

	for (int u: g[v])
	{
		if (vis[u] && d[u] == d[v]) flag = 2; 
		if (vis[u]) continue;
		if (!flag) flag = 1;
		d[u] = 3 - d[v];
		dfs(u);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		u--, v--;

		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			flag = 0;
			d[i] = 1;
			dfs(i);	
		
			cnt[flag]++;
		}
	}

	ans += 2ll * cnt[0] * (n - cnt[0]);
	ans += 1ll * cnt[0] * cnt[0];

	ans += 2 * cnt[1];
	ans += cnt[2];

	ans += 2ll * cnt[1] * (cnt[1] - 1);
	ans += 1ll * cnt[2] * (cnt[2] - 1);
	ans += 2ll * cnt[1] * cnt[2];

	cout << ans << '\n';
}
