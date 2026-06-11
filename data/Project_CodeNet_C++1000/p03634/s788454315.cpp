#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const ll siz = 1e5 + 7;
vector < pi> adj[siz];
ll n, k, q;
vector<ll>dis(siz, 1e15);
vector<bool>vis(siz, false);
void bfs(ll node) {
	dis[node] = 0;
	vis[node] = false;
	queue<ll>q;
	q.push(node);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto k : adj[v]) {
			if (!vis[k.fi]) {
				dis[k.fi] = min(dis[k.fi], k.se + dis[v]);
				vis[k.fi] = true;
				q.push(k.fi);
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (ll i = 0; i < n - 1; i++) {
		ll u, v, len;
		cin >> u >> v >> len;
		--u, --v;
		adj[u].pb({v, len});
		adj[v].pb({u, len});
	}
	cin >> q >> k;
	--k;
	bfs(k);
	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		--x, --y;
		cout << abs(dis[x] - dis[k]) + abs(dis[y] - dis[k]) << endl;
	}
}