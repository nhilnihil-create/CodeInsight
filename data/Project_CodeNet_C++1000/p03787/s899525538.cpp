#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	vector<vector<int> > G(N);
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i];
		a[i]--; 
		b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	vector<int> dist(N, -1);
	int cnt = 0, compcnt = 0, biparcnt = 0;
	for (int i = 0; i < N; i++) {
		if (!G[i].empty()) cnt++;
		if (dist[i] != -1) continue;
		dist[i] = 0;
		queue<int> que; que.push(i);
		bool bipartite = true;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int j : G[u]) {
				if (dist[j] == -1) {
					dist[j] = dist[u] ^ 1;
					que.push(j);
				}
				if (dist[j] == dist[u]) {
					bipartite = false;
				}
			}
		}
		if (!G[i].empty()) {
			compcnt++;
			if (bipartite) biparcnt++;
		}
	}
	cout << 1LL * N * N - 1LL * cnt * cnt + 1LL * compcnt * compcnt + 1LL * biparcnt * biparcnt << "\n";
	return 0;
}