// In The Namw Of Allah
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef pair <int, int> pii;
typedef long long ll;

int dist[N], dp[N], col[N], vis[N];
vector <pair <int, pii>> v;
vector <int> adj[N];

void bfs(int v, int d, int c) {
	queue <int> q;
	dist[v] = d + 1;
	vector <int> vc;
	q.push(v);
	vis[v] = 1;
	while(!q.empty()) {
		v = q.front(), q.pop();
		vc.push_back(v);
		for (auto u : adj[v]) {
			if(!vis[u] && dp[u] < dist[v] - 1) {
				q.push(u);
				vis[u] = 1;
				dist[u] = dist[v] - 1;
			}
		}
	}
	while(!vc.empty()) {
		v = vc.back();
		vc.pop_back();
		if(!col[v])	col[v] = c;
		vis[v] = 0, dp[v] = dist[v], dist[v] = 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v].push_back(u), adj[u].push_back(v);
	}
	int tc;
	cin >> tc;
	while(tc--) {
		int u, d, c;
		cin >> u >> d >> c;
		u--;
		v.push_back({d, {u, c}});
	}
	while(!v.empty()) {
		bfs(v.back().second.first, v.back().first, v.back().second.second);
		v.pop_back();
	}
	for (int i = 0; i < n; i++)	cout << col[i] << "\n";
}