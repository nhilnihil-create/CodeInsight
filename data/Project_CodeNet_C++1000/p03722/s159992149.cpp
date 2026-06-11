#include "bits/stdc++.h"
using namespace std;

struct Edge {
	long long cost;
	int from, to;
	Edge() {}
	Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};

static const int MAX = 1000;
static const long long INF = 1000000000000000LL;
int N, M;
Edge e[2 * MAX];
long long d[MAX];

bool bellman_ford() {
	for (int i = 0; i < MAX; i++) {
		d[i] = INF;
	}
	// 頂点 0 からスタート
	d[0] = 0;
	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < M; j++) {
			if (d[e[j].from] != INF && d[e[j].to] > d[e[j].from] + e[j].cost) {
				d[e[j].to] = d[e[j].from] + e[j].cost;
				if (i >= N - 1 && e[j].to == N - 1) return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		e[i] = Edge(a - 1, b - 1, -c);
	}
	if (bellman_ford()) {
		cout << "inf" << endl;
	}
	else {
		cout << -d[N - 1] << endl;
	}
	return 0;
}
