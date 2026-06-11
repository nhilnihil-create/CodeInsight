#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
    int to;
    ll cost;
};
using Graph = vector<vector<Edge>>;

// 幅優先探索
vector<ll> dist;  // 始点からの距離を記録
void bfs(const Graph &G, int s) {
    const ll INF = 1e15;
    dist.assign((int)G.size(), INF);  // 初期化

    queue<int> que;
    que.emplace(s);  // sから探索する
    dist[s] = 0;
    while (que.size() != 0) {   // 幅優先探索
        int now = que.front();  // 現在の状態
        que.pop();
        for (auto e : G[now]) {
            if (dist[e.to] == INF) {  // 未探索の時のみ行う
                dist[e.to] = dist[now] + e.cost;
                que.emplace(e.to);
            }
        }
    }
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    int V;
    cin >> V;

    Graph G(V);
    for (int i = 0; i < V - 1; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    vector<int> x(Q), y(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x.at(i) >> y.at(i);
        x[i]--, y[i]--;
    }
    bfs(G, K);

    for (int i = 0; i < Q; i++) {
        cout << dist[x[i]] + dist[y[i]] << "\n";
    }

    return 0;
}
