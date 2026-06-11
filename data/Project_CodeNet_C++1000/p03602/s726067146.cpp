#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct edge {
	int s, t, cost;
	edge(int s, int t, int cost) : s(s), t(t), cost(cost) {}
};

int main() {
	int N; cin >> N;
	vector<edge> e;
	vector<vector<int>> goal(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int a; cin >> a;
			goal[i][j] = a;
			if (i < j)
				e.push_back(edge(i, j, a));
		}
	}
	sort(e.begin(), e.end(), [&](edge e1, edge e2) { return e1.cost < e2.cost; });

	vector<vector<ll>> mn_cost(N, vector<ll>(N, (1LL << 60)));
	for (int i = 0; i < N; ++i)
		mn_cost[i][i] = 0;
	ll res = 0;
	for (auto ei : e) {
		int s = ei.s, t = ei.t;
		int cost = ei.cost;
		if (mn_cost[s][t] < cost) {
			cout << -1 << endl;
			return 0;
		}
		else if (mn_cost[s][t] > cost) {
			res += cost;
			for (int i = 0; i < N; ++i) {
				for (int j = i + 1; j < N; ++j) {
					ll new_path1 = mn_cost[i][s] + mn_cost[t][j] + cost;
					ll new_path2 = mn_cost[i][t] + mn_cost[s][j] + cost;
					ll new_path = min(new_path1, new_path2);
					if (new_path < goal[i][j]) {
						cout << -1 << endl;
						return 0;
					}
					mn_cost[i][j] = mn_cost[j][i] = min(mn_cost[i][j], new_path);
				}
			}
		}
	}
	cout << res << endl;

	return 0;
}