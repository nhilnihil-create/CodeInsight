#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 2e3 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, k, dist[maxn], ans = mod;
vector<int> graph[maxn];
pair<int, int> edge[maxn];

void dfs(int u)
{
	for (int i : graph[u])
		if (dist[i] == -1)
		{
			dist[i] = dist[u] + 1;
			dfs(i);
		}
}

void handle(int val)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (dist[i] > val);
	ans = min(ans, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v, u--, v--;
		graph[u].pb(v), graph[v].pb(u);
		edge[i] = mp(u, v);
	}
	for (int i = 0; i < n; i++)
	{
		memset(dist, -1, sizeof(dist));
		dist[i] = 0;
		dfs(i);
		handle(k / 2);
	}
	for (int i = 0; i < n; i++)
	{
		memset(dist, -1, sizeof(dist));
		dist[edge[i].ff] = 0;
		dist[edge[i].ss] = 0;
		dfs(edge[i].ff);
		dfs(edge[i].ss);
		handle((k - 1) / 2);
	}
	cout << ans << endl;
}

