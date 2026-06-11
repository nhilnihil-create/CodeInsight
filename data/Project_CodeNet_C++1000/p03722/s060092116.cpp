#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

struct Edge {
	int from;
	int to;
	int cost;
};

const ll INF = 1LL << 60;

int main() {
  int n, m;
	cin >> n >> m;
	vector<Edge> g(m);
	rep(i, m) {
		cin >> g[i].from >> g[i].to >> g[i].cost;
		g[i].from--, g[i].to--;
	}
	vector<ll> ans(n, -INF);
	ans[0] = 0;
	rep(i, n) rep(j, m) {
		Edge e = g[j];
		if (ans[e.from] == -INF) continue;
		if (ans[e.from] + e.cost > ans[e.to]) {
			ans[e.to] = ans[e.from] + e.cost;
			if (i == n - 1 && e.to == n - 1) {
				cout << "inf" << endl;
				return 0;
			}
		}
	}
	cout << ans[n - 1] << endl;
	return 0;
}
