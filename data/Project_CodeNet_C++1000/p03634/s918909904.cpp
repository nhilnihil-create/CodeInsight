#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Tree {
	using T = pair<ll, int>;
	int n;
	vector<vector<T>> edge;
	vector<ll> d;

public:
	Tree(int N) : n(N), edge(N), d(N, INT64_MAX) {}
	void add(int a, int b, ll c) {
		edge[a].emplace_back(c, b);
		edge[b].emplace_back(c, a);
	}
	void dfs(int k, int p = -1) {
		if (p < 0) d[k] = 0;
		for (auto &t : edge[k]) {
			ll c;
			int j;
			tie(c, j) = t;
			if (j == p) continue;
			d[j] = d[k] + c;
			dfs(j, k);
		}
	}
	ll distance(int i) {
		return d[i];
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	Tree tree(N);
	REP(i, N - 1) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		--a;
		--b;
		tree.add(a, b, c);
	}
	int Q, K;
	cin >> Q >> K;
	--K;
	tree.dfs(K);
	REP(i, Q) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		cout << tree.distance(x) + tree.distance(y) << endl;
	}

	return 0;
}