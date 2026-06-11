// https://atcoder.jp/contests/abc061/tasks/abc061_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

template <typename T> struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

template <typename T> vector<T> bellman_ford(Edges<T> &edges, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; i++) {
        for (auto &e : edges) {
            if (dist[e.src] == INF)
                continue;
            if (dist[e.to] > dist[e.src] + e.cost) {
                dist[e.to] = dist[e.src] + e.cost;
                // 一番離れた頂点間はN-1なので、N回目のループでコストが小さくなったら負閉路がある
                // 後者の条件は通常のベルマンフォード法では不要だが、今回は頂点Nのスコアに影響する負閉路のみを検出する
                if (i == V - 1 && e.to == V - 1) {
                    return vector<T>();
                }
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    Edges<ll> es;
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        es.emplace_back(a - 1, b - 1, -c);
    }
    auto dists = bellman_ford(es, N, 0);
    if (dists.size() == 0) {
        cout << "inf\n";
    } else {
        cout << -dists.back() << "\n";
    }

    return 0;
}
