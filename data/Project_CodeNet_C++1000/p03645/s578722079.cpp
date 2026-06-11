#include "bits/stdc++.h"

using namespace std;

const int mx = 200000 + 9;

bitset <mx> mark;
int d[mx];
vector <int> adj[mx];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    mark[1] = 1;
    queue <int> q;
    q.push(1);

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (mark[v]) continue;
            mark[v] = 1;
            d[v] = 1 + d[u];
            q.push(v);
        }
    }

    if (d[n] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}