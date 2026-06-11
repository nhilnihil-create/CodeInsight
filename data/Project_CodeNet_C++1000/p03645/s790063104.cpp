#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = j; i < n; ++i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;



int main() {
	int n, m, a, b; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>());
	rep(i, 0, m) {
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<i64> dist(n, INF);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while (q.size()) {
		int v = q.front(); q.pop();
		for (int nv : g[v]) {
			if (dist[nv] == INF) {
				dist[nv] = dist[v] + 1;
				q.push(nv);
			}
		}
	}

	if (dist[n - 1] == 2) {
		cout << "POSSIBLE";
	}
	else {
		cout << "IMPOSSIBLE";
	}
	return 0;
}