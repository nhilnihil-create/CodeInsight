
// D - Score Attack

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 9223372036854775807;
const int MAX_V = 1000;
const int MAX_E = 2000;


struct Edge {
	int from;
	int to;
	ll cost;
};

Edge edges[MAX_E];
ll min_d[MAX_V]; // 最短距離
int V, E, r;

void bellman_ford(int s) {
  bool negative_cycle = false;

	for (int i=0; i<V; i++) {
		min_d[i] = INF;
	}

	min_d[s] = 0;

	int update_cnt = 0;
	while (true) {
		bool update = false;
		for (int i=0; i<E; i++) {
			Edge e = edges[i];
			if (min_d[e.from] == INF) continue;
			if (min_d[e.to] > min_d[e.from] + e.cost) {
				min_d[e.to] = min_d[e.from] + e.cost;
				update = true;
			}
		}

		if (!update) break;
		else update_cnt++;

		if (update_cnt >= V) {
			negative_cycle = true;
			break;
		}
	}

	if (!negative_cycle) return;

	// set negative cycle to -INF
	update_cnt = 0;
	while (true) {
		bool update = false;
		for (int i=0; i<E; i++) {
			Edge e = edges[i];
			if (min_d[e.from] == INF || min_d[e.to] == -INF) continue;
			if (min_d[e.from] == -INF || min_d[e.to] > min_d[e.from] + e.cost) {
				min_d[e.to] = -INF;
				update = true;
			}
		}

		if (!update) break;
		else update_cnt++;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	V = N;
	E = M;

	int a, b, c;
	for (int i=0; i<E; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		edges[i] = {a, b, -c};
	}

	bellman_ford(0);

	if (min_d[N-1] == -INF) {
		cout << "inf" << endl;
	} else {
		cout << -min_d[N-1] << endl;
	}

	return 0;
}