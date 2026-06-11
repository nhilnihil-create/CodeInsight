#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int limit = 100010;
struct edge{
	int to;
	long long cost;
};
vector<edge> tree[limit];
long long depth[limit];
void dfs(int v, int p, long long d) {
	depth[v] = d;
	for (auto &e:tree[v]) {
		if (e.to == p) continue;
		dfs(e.to, v, d + e.cost);
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}

	int q, k;
	cin >> q >> k;
	k--;

	dfs(k, -1, 0);
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << depth[x] + depth[y] << endl;
	}

	return 0;
}
