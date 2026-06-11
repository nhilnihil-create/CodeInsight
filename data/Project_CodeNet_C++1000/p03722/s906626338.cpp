#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
template<class T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return 1; } return 0; }

int N, M;
vector<bool> visit;
vector<bool> seen;

void dfs(int v, const vector<vector<int>> &G) {
    if (seen[v]) return;
    visit[v] = true; seen[v] = true;
    for (auto u : G[v]) if (!seen[u]) dfs(u, G);
}

template<typename T>
pair<bool, vector<T>> bellmanford(const vector<vector<pair<int, T>>> &G, int s) {
    const T inf = numeric_limits<T>::max();
    int V = G.size();
    vector<T> dist(V, inf); dist[s] = 0;
    bool negative_cycle = false;
    
    for (int relax = 0; relax <= V; relax++) {
        for (int from = 0; from < V; from++) {
            for (const auto &e : G[from]) {
                int to; T cost; tie(to, cost) = e;
                if (dist[from] == inf) continue;
                if (dist[from] + cost < dist[to]) {
                    dist[to] = dist[from] + cost;
                    if (relax == V && visit[to]) negative_cycle = true;
                }
            }
        }
    }
    return {negative_cycle, dist};
}

signed main() {
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    vector<vector<int>> H(N);
    seen.resize(N, false);
    visit.resize(N, false);
    for (int i = 0; i < M; i++) {
        int v, u, c; cin >> v >> u >> c; v--; u--;
        G[v].emplace_back(u, -c);
        H[u].emplace_back(v);
    }
    
    dfs(N-1, H);
    
    bool neg; vector<int> dist;
    tie(neg, dist) = bellmanford(G, 0);
    
    int ans = -dist[N-1];
    if (neg) cout << "inf" << endl;
    else cout << ans << endl;
    return 0;
}
