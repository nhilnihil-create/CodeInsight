/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<pair<long long,int>>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int queries, k;
    cin >> queries >> k;
    k--;
    
    priority_queue<pair<long long,int>> q;
    vector<long long> dist(n, -1);
    q.push({0, k});
    while (!q.empty()) {
        auto node = q.top();
        q.pop();
        long long d = -node.first;
        int u = node.second;
        dist[u] = d;
        
        for (auto e : adj[u]) {
            int w = e.first, v = e.second;
            if (dist[v] != -1) continue;
            q.push({-(d + w), v});
        }
    }
    
    for (int i = 0; i < queries; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << dist[u] + dist[v] << '\n';
    }
    return 0;
}