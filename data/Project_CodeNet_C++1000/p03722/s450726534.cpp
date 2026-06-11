#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 1000

template <typename T>
struct edge {
    int from, to;
    T cost;
    edge(int from, int to, T cost = 1) : from(from), to(to), cost(cost) {}
    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};

/*
    sからたどりつける負の閉路を検出したとき、空の vector を返す
    頂点数 V, 始点 s, 辺の集合 es, INF として LINF を使うとき :
    vector<ll> dist = BellmanFord(V, s, es, LINF);
*/
template <typename T>
vector<T> BellmanFord(int V, int s, vector<edge<T>>& es, const T INF = 1e9) {
    vector<T> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (edge<T>& e : es) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for (edge<T>& e : es) {
        if (dist[e.from] == INF) continue;
        if (dist[e.from] + e.cost < dist[e.to]) return vector<T>();
    }
    return dist;
}

template <typename T>
bool FindNegativeLoop(int V, vector<edge<T>>& es) {
    vector<T> dist(V, 0);
    for (int i = 0; i < V; i++) {
        for (edge<T>& e : es) {
            if (dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == V - 1) return true;
            }
        }
    }
    return false;
}

bool visited[MAX];
vector<int> G[MAX];

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    for (int to : G[cur]) {
        dfs(to);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    ll c[m];
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        G[b[i]].emplace_back(a[i]);
    }
    dfs(n - 1);
    vector<edge<ll>> es;
    rep(i, m) {
        if (!visited[a[i]] || !visited[b[i]]) continue;
        es.emplace_back(a[i], b[i], -c[i]);
    }
    auto dist = BellmanFord(n, 0, es, LINF);
    if (dist.empty())
        cout << "inf" << endl;
    else
        cout << -dist[n - 1] << endl;
    return 0;
}