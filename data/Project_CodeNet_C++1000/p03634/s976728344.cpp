#include <bits/stdc++.h>
#define sz(a) (int)a.size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
const ll MOD = (ll)1e9 + 7;
vector<ll> dist;

void dfs(int u, int par, const vector<vector<pair<int, int>>>& adj) {
    for(auto& node: adj[u]) {
        int v = node.first;
        int cost = node.second;
        if(v == par) continue;
        dist[v] = dist[u] + cost;
        dfs(v, u, adj);
    }
}

int main() {
    int n;
    cin >> n;
    dist.assign(n + 10, 0);
    vector<vector<pair<int, int>>> adj(n + 2);
    rep(i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    int q, k;
    cin >> q >> k;
    dfs(k, k, adj);
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] << "\n";
    }
    return 0;
}