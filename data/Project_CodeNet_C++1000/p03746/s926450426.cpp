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
bool vis[N];
vector <int> g[N];

int x, y;

vector <int> v1, v2;

void dfs (int v, vector <int> &vec)
{
	vis[v] = 1;
	vec.pb(v);

	for (int u : g[v])
		if (!vis[u])
		{
			dfs(u, vec);
			return;
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

		if (!i) x = u, y = v;

		g[u].pb(v);
		g[v].pb(u);
	}

	vis[x] = vis[y] = 1;

	dfs(x, v1);
	dfs(y, v2);

	reverse(v1.begin(), v1.end());

	cout << _sz(v1) + _sz(v2) << '\n';
	for (int x : v1) cout << x + 1 << ' ';
	for (int x : v2) cout << x + 1 << ' ';
	cout << '\n';
}
