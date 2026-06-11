#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 * 1000 + 20;

int n, k, l, a, b, g[MAXN], ans[MAXN], cnt;
vector <int> adj[MAXN], adj2[MAXN], tmp;
map <int, int> mp;
bitset <MAXN> connect;
bool vis[MAXN], vis2[MAXN];

void dfs(int v) {
	vis[v] = true;
	g[v] = cnt;
	connect[v] = 1;
	for (int u: adj[v])
		if (!vis[u])
			dfs(u);
}

void dfs2(int v) {
	vis2[v] = true;
	tmp.push_back(v);
	for (int u: adj2[v])
		if (!vis2[u])
			dfs2(u);
}

int main() {
	ios:: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k >> l;
	for (int i = 0; i < k; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	for (int i = 0; i < l; i++)
		cin >> a >> b, adj2[a].push_back(b), adj2[b].push_back(a);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis2[i]) {
			dfs2(i);
			for (int a: tmp)
				mp[g[a]]++;
			for (int a: tmp)
				ans[a] = mp[g[a]];
		}
		mp.clear(), tmp.clear();
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
