// 5/28
// 2-5-4 ベルマンフォード
// bellman_ford.cppとは違い、ABC061-Dのような、
// 「特定の頂点の値が発散するかどうか」が解けるように改良したもの。
// https://atcoder.jp/contests/abc061/tasks/abc061_d
// ベルマンフォード は負の回路ができると発散すると言われるが、
// 厳密に言うと発散しない点もある。実際に発散するのは負の回路に含まれる頂点か、
// その回路からパスが引ける頂点のみ。

// 完全にC++で実装するとたぶんこんな感じ。
// https://ta7uw.hatenablog.com/entry/2019/12/31/201242

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = LONG_MAX;

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int f, int t, ll c) : from(f), to(t), cost(c) { }
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};
using Graph = vector<Edge>;

vector<bool> negative;  // 個別の頂点が発散するかどうかを測定
vector<ll> dist;  // 個別の頂点までの最短距離を格納

// 負の回路があるかどうかを返す。
bool bellman_ford(int N, Graph& es, int s) {
    // 初期化
    dist.assign(N, INF);
    dist[s] = 0;
    negative.assign(N, false);

    bool have_negative_cycle = false;

    // 辺の緩和を反復
    rep(i, N) {
        for (auto e : es) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == N - 1) {
                    negative[e.to] = true;
                    have_negative_cycle = true;
                }
            }
            if (negative[e.from]) {
                negative[e.to] = true;
                // ここの実装は甘いかもしれない。ABC061-DはAC通る。
                // https://ta7uw.hatenablog.com/entry/2019/12/31/201242
            }
        }
    }

    // 負の回路があるかどうかを返す。
    return have_negative_cycle;
}

// ABC061-Dによる実装サンプル
int main() {
    int N;  // 与えられた有向グラフの頂点の数
    int M;  // 同辺の数（辺の重みは負の場合がある）
    cin >> N >> M;

    vector<Edge> es;
    rep(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        es.push_back(Edge(a, b, -c));
    }

    bool have_negative_cycle = bellman_ford(N, es, 0);

    // if (d[0] == -1) cout << "inf" << endl;
    if (negative[N - 1]) cout << "inf" << endl;
    else cout << -dist[N - 1] << endl;
}
