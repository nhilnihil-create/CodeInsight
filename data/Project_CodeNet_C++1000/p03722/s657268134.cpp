#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
constexpr i64 INF = 1LL << 60;

struct edge {
	int from, to;
	i64 cost;
	edge(int f, int t, i64 c): from(f), to(t), cost(c) {}
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<edge> edges;
	rep(i, 0, m) {
		int a, b;
		i64 c;
		cin >> a >> b >> c;
		--a, --b;
		edges.emplace_back(a, b, -c);
	}

	vector<i64> dist(n, INF);
	dist[0] = 0;
	rep(i, 0, n) {
		bool updated = false;
		for (edge e : edges) {
			if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] + e.cost;
				if (i == n - 1 && e.to == n - 1) {
					cout << "inf" << '\n';
					return 0;
				}
			}
		}
	}

	cout << -dist[n - 1] << '\n';
	return 0;
}