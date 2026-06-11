#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 1e5 + 10;

int n, m;
int u, v;
int vis[MAXN];
vector <int> adj[MAXN];
deque <int> par;

void dfs(int root) {
    for (auto y: adj[root])
        if (!vis[y]) {
            vis[y] = true;
            par.push_front(y);
            dfs(y);
            break;
        }
}
void dfs_2(int root) {
    for (auto y: adj[root])
        if (!vis[y]) {
            vis[y] = true;
            par.pb(y);
            dfs_2(y);
            break;
        }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vis[1] = true;
    par.push_front(1);
    dfs(1);
    dfs_2(1);
    
    int sz = par.size();
    cout << sz << '\n';
    for (auto y: par)
        cout << y << ' ';
    return 0;
}