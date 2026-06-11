#include <bits/stdc++.h>

using namespace std;
#define MAXN 100
vector<pair<int,int>> adj[MAXN + 5];

void djikstra(int s, vector<int>& dist, vector<bool>& proc) {
	priority_queue<pair<int,int>> q;
	dist[s] = 0;
	q.push({-dist[s], s});
	while(!q.empty()) {
		int t = q.top().second; q.pop();
		if (proc[t]) continue;
		for (auto& ei : adj[t]) {
			int u, w;
			tie(u, w) = ei;
			if (dist[u] > dist[t] + w) {
				dist[u] = dist[t] + w;
				q.push({-dist[u], u});
			}
		}
		proc[t] = true;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, cnt = 0; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	for (int i = 1; i <= n; i++) {
		vector<int> dist(n+1, INT_MAX);
		vector<bool> proc(n+1, false);
		djikstra(i, dist, proc);
		for (auto& ei : adj[i]) {
			int u, w;
			tie(u, w) = ei;
			if (dist[u] < w) cnt++;
		}
	}

	cout << cnt/2 << "\n";
	return 0;
}