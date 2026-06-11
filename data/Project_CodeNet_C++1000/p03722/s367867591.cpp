#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
using namespace std;

bool chmin(int &x, const int y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

struct edge {
    int from, to, cost;
    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

vector<int> bellman_ford(vector<edge> &graph, int n, int s) {
    const int inf = 1LL << 60;
    vector<int> dist(n, inf);
    vector<bool> flag(n, false);

    dist[s] = 0;
    rep(i, 0, n - 1) {
        for (auto e : graph) {
            if (dist[e.from] == inf) continue;
            chmin(dist[e.to], dist[e.from] + e.cost);
        }
    }

    for (auto e : graph) {
        if (dist[e.from] == inf) continue;
        if (chmin(dist[e.to], dist[e.from] + e.cost)) flag[e.to] = true;
        if (flag[e.from]) flag[e.to] = true;
    }

    if (flag[n - 1]) return vector<int>();
    return dist;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<edge> graph;
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back(edge(--a, --b, -c));
    }

    auto ans = bellman_ford(graph, n, 0);
    if (ans.size()) {
        cout << -ans[n - 1] << endl;
    } else {
        cout << "inf" << endl;
    }
    
    return 0;
}