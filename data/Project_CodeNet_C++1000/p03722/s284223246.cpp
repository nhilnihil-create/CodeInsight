#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

struct edge {
	int from, to, cost;
	edge(int f, int t, int c): from(f), to(t), cost(c) {}
};

int main() {
	int n, m; cin >> n >> m;

	vector<edge> edges;
	vector<i64> dist(n, INF);
	rep(i, 0, m) {
		i64 a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		edges.emplace_back(a, b, -c);
	}

	dist[0] = 0;
	rep(i, 0, n * 2) {
		bool updated = false;

		for (auto e : edges) {
			if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {
				updated = true;
				dist[e.to] = dist[e.from] + e.cost;
				// 閉路の後にゴールがないとだめ
				if (i >= n && e.to == n - 1) {
					cout << "inf" << endl;
					return 0;
				}
			}
		}
	}
	cout << -dist[n - 1] << endl;

	return 0;
}