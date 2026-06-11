#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<int> q;
	q.push(0);
	const int inf = 1e9;
	vector<int> d(n, inf);
	d[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto nv : g[v]) {
			if (d[nv] != inf) continue;
			d[nv] = d[v] + 1;
			q.push(nv);
		}
	}

	// priority_queue<pii, vector<pii>> q;
	// q.push(make_pair(0, 0));
	// vector<int> d(n, 1e9);
	// d[0] = 0;
	// while (!q.empty()) {
	// 	pii p = q.top();
	// 	q.pop();
	// 	if (d[p.second] < p.first) continue;
	// 	for (auto a : g[p.second]) {
	// 		if (d[a] > p.first + 1) {
	// 			d[a] = p.first + 1;
	// 			q.push(make_pair(d[a], a));
	// 		}
	// 	}
	// }

	if (d[n - 1] <= 2) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE " << endl;
	return 0;
}