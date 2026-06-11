#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int, ll>>>;
void dfs(int v, int p, Graph &edge, vector<ll> &dist) {
    auto &c = dist[v];
    for (auto x: edge[v]) {
        if (x.first == p) continue;
        dist[x.first] = x.second + c;
        dfs(x.first, v, edge, dist);
    }
}

int main() {
    int n;
    cin >> n;
    Graph edge(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    int q, k;
    cin >> q >> k;
    k--;
    vector<ll> dist(n);
    dist[k] = 0;
    dfs(k, -1, edge, dist);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }
    return 0;
}