#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
constexpr i64 INF = 1LL << 60;

struct edge {
	int to;
	i64 cost;
	edge(int t, i64 c) : to(t), cost(c) {}
};

vector<edge> g[100000];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n, a, b, q, k, x, y; cin >> n;
	i64 c;
	rep(i, 0, n - 1) {
		cin >> a >> b >> c;
		--a, --b;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	cin >> q >> k;
	--k;

	queue<int> que;
	vector<i64> dist(n, INF);
	que.emplace(k);
	dist[k] = 0;
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (edge e : g[v]) {
			if (dist[e.to] == INF) {
				que.emplace(e.to);
				dist[e.to] = e.cost + dist[v];
			}
		}
	}

	rep(i, 0, q) {
		cin >> x >> y;
		--x, --y;
		cout << dist[x] + dist[y] << '\n';
	}
	return 0;
}