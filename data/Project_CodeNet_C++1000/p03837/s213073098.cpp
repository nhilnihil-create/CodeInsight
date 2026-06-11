// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
vector<pair<int,int>> adj[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<pair<int,pair<int,int>>> edges;

	for(int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		edges.push_back(make_pair(c, make_pair(u, v)));
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}

	auto dist = [&](int s, int t) {
		vector<int> d(n, 1e9);
		d[s] = 0;
		priority_queue<pair<int,int>> pq;
		pq.push(make_pair(0, s));
		while(!pq.empty()) {
			int now = pq.top().second;
			pq.pop();
			for(pair<int,int> v : adj[now]) {
				if(d[v.first] > d[now] + v.second) {
					d[v.first] = d[now] + v.second;
					pq.push(make_pair(-d[v.first], v.first));
				}
			}
		}
		return d[t];
	};

	int ans = 0;

	for(auto m : edges) {
		if(dist(m.second.first, m.second.second) < m.first) ans++;
	}
	
	cout << ans;



	return 0;
}
