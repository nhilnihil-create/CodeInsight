#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> G(N);
	for(int i=0;i<M;i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int Q;
	cin >> Q;

	vector<int> v(Q), d(Q), c(Q);
	for(int i=0;i<Q;i++) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	vector<int> color(N, 0);
	vector<int> same_rad(N, -1);
	for(int i=Q-1;i>=0;i--) {
		if (same_rad[v[i]] >= d[i]) continue;
		same_rad[v[i]] = d[i];

		// (vertex, rest)
		queue<pair<int, int>> que;
		que.emplace(v[i], d[i]);
		while(que.size()) {
			auto p = que.front();
			que.pop();
			if(color[p.first] == 0) {
				color[p.first] = c[i];
			}
			if(p.second > 0) {
				for(int to : G[p.first]) {
					if(same_rad[to] < p.second - 1) {
						same_rad[to] = p.second - 1;
						que.emplace(to, p.second - 1);
					}
				}
			}
		}
	}
	for(int a : color) {
		cout << a << endl;
	}

	return 0;
}
