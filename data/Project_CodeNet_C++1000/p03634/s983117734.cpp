#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge {
	int to; // 辺の行き先
	ll cost; // その辺を通るコスト
	Edge(int t, ll c) : to(t), cost(c) { }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int N; cin >> N;
	vector<int> a(N), b(N);
	vector<ll> c(N); REP(i, N - 1) cin >> a[i] >> b[i] >> c[i];
	REP(i, N - 1) {
		a[i]--;
		b[i]--;
	}
	int Q; cin >> Q;
	int K; cin >> K; K--;
	vector<int> x(Q), y(Q); REP(i, Q) cin >> x[i] >> y[i];
	REP(i, Q) {
		x[i]--;
		y[i]--;
	}

	// 最短距離を初期化
	vector<ll> d(N, (ll)1e18);
	d[K] = 0;
	// グラフを隣接リストでセットする
	vector<vector<Edge> > G(N);
	REP(i, N - 1) {
		G[a[i]].push_back(Edge(b[i], c[i]));
		G[b[i]].push_back(Edge(a[i], c[i]));
	}
	// 距離が小さい順に取り出せるようgreater<P>を指定
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, K));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second; // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) continue;
        for (auto e : G[v]) { // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

	REP(i, Q)
		cout << d[x[i]] + d[y[i]] << '\n';
    return 0;
}
