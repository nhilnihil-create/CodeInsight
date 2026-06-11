#include<bits/stdc++.h>
using namespace std;

int n, u, v, root;
int visited[100001], a[100001];
vector <int> adj[100001];

bool dfs(int u) {
    visited[u] = 1;
    if(adj[u].size() == 1) return 1;
    int sum = 0, mx = -1;
    for(auto v : adj[u]) {
        if (!visited[v]) {
            if(!dfs(v)) return 0;
            sum += a[v];
            mx = max(mx, a[v]);
        }
    }
    if(mx <= a[u] && a[u] <= sum && sum <= a[u] << 1) {
        a[u] = (a[u] << 1) - sum;
        if (u == root) return !a[u];
        return 1;
    }
    return 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    root = 1;
    for (int i = 1; i <= n; i++) if (adj[i].size() > adj[root].size()) root = i;
    if (adj[root].size() == 1) cout << (a[1] == a[2] ? "YES" : "NO");
    else cout << (dfs(root) ? "YES" : "NO");
}