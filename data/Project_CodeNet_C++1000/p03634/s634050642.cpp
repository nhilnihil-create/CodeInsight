
// D - Transit Tree Path

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

struct Edge {
	int to_idx;
	ll cost;
};

struct Node {
	vector<Edge> edges;
	ll total_cost = 0;
	bool visited = false;
};

Node nodes[100000];

void dfs(int idx, ll total_cost) {
	nodes[idx].total_cost = total_cost;
	nodes[idx].visited = true;

	for (Edge e : nodes[idx].edges) {
		if (nodes[e.to_idx].visited) continue;
		dfs(e.to_idx, total_cost + e.cost);
	}
}

int main() {
	int N;
	cin >> N;

	int a, b, c;
	for (int i=0; i<N-1; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		nodes[a].edges.push_back(Edge{b, c});
		nodes[b].edges.push_back(Edge{a, c});
	}

	int Q, K;
	cin >> Q >> K;
	K--;

	dfs(K, 0);

	int x, y;
	vector<ll> ans;
	for (int i=0; i<Q; i++) {
		cin >> x >> y;
		x--;
		y--;

		ans.push_back(nodes[x].total_cost + nodes[y].total_cost);
	}

	for (ll a : ans) {
		cout << a << endl;
	}

	return 0;
}