#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct edge {
    int from, to, cost;
};
struct graph {
    int n;
    vector<vector<edge>> G;
    vector<bool> visited;
    graph(int n_) {
        n = n_;
        G.resize(n);
        visited.resize(n, false);
    }
    void add_edge(int from, int to, int cost) {
        G[from].push_back({from, to, cost});
    }
    void dfs(int s, int i, int _n) { // 深さ制限探索
        visited[s] = true;
        if (i == _n) return;
        for (edge e : G[s]) {
            if (visited[e.to]) continue;
            dfs(e.to, i + 1, _n);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    graph G(n);
    rep(i, m) {
        int from, to, cost = 0;
        cin >> from >> to;
        from--; to--;
        G.add_edge(from, to, cost);
    }
    G.dfs(0, 0, 2);
    cout << (G.visited[n-1] ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}