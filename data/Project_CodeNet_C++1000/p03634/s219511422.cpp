#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge {
	int to; ll len;
};

ll dist[100005];
vector<Edge> G[100005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	rep(i, 1, n) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back(Edge { b, c });
		G[b].push_back(Edge { a, c });
	}

	int q; cin >> q;
	int k; cin >> k;

	auto dfs = [&](auto&& dfs, int n, int p = -1) -> void {
		if (p == -1) {
			dist[n] = 0;
		}

		for (const Edge& e : G[n]) if (e.to != p) {
			dist[e.to] = dist[n] + e.len;
			dfs(dfs, e.to, n);
		}
	};
	dfs(dfs, k);

	rep(i, 0, q) {
		int a, b; cin >> a >> b;
		cout << dist[a] + dist[b] << endl;
	}
}

