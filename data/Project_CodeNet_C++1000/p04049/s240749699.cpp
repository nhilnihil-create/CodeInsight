#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 1000 + 17;

int n, k, ans = 1e9 + 17;
vector<int> adj[MAXN];
vector<pii> ed;

int bfs(int x, int y) {
	queue<int> q;
	int lev[MAXN] = {};
	fill(lev, lev + MAXN, 1e9);
	lev[x] = 0;
	lev[y] = 0;
	if (y != 0)
		q.push(y);
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		//cerr << u << endl;
		for (auto v : adj[u])
			if (lev[v] == 1e9) {
				lev[v] = lev[u] + 1;
				q.push(v);
			}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (lev[i] > (k / 2))
			res++;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		ed.pb({v, u});
		adj[v].pb(u);
		adj[u].pb(v);
	}
	if (k % 2 == 0)
		for (int i = 1; i <= n; i++)
			ans = min(ans, bfs(i, 0));
	else
		for (auto i : ed)
			ans = min(ans, bfs(i.ff, i.ss));
	cout << ans << endl;
	return 0;
}
