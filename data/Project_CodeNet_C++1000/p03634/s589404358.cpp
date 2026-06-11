// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

long long d[N];
vector<pair<int,int>> adj[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int q, k;
	cin >> q >> k;
	k--;
	for(int i = 0; i < n; i++) d[i] = 1e16;
	d[k] = 0;
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, k));
	while(!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for(pair<int,int> pv : adj[now]) {
			if(d[pv.first] > d[now] + pv.second) {
				d[pv.first] = d[now] + pv.second;
				pq.push(make_pair(-d[pv.first], pv.first));
			}
		}
	}
	for(int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		cout << d[u]+d[v] << "\n";
	}
	return 0;
}
