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

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, m, comp[maxn], compCount, sz[maxn], color[maxn];
bool isBip[maxn];
vector<int> graph[maxn];

void dfs(int u, int clr)
{
	color[u] = clr;
	comp[u] = compCount;
	sz[compCount]++;
	for (int i : graph[u])
	{
		if (color[i] == -1)
			dfs(i, 1 - clr);
		else if (color[i] == color[u])
			isBip[compCount] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(color, -1, sizeof(color));
	memset(isBip, true, sizeof(isBip));

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[--u].pb(--v);
		graph[v].pb(u);
	}
	for (int i = 0; i < n; i++)
		if (color[i] == -1)
			dfs(i, 0), compCount++;
	ll oneCount = 0, bipCount = 0;
	for (int i = 0; i < compCount; i++)
	{
		if (sz[i] == 1)
			oneCount++;
		else
			bipCount += isBip[i];
	}
	ll ans = compCount - oneCount + bipCount;
	ans += oneCount * oneCount + 2 * oneCount * (n - oneCount);
	ans += 2 * bipCount * (bipCount - 1);
	ans += 2 * bipCount * (compCount - oneCount - bipCount);
	ans += (compCount - oneCount - bipCount) * (compCount - oneCount - bipCount - 1);
	cout << ans << endl;
}

