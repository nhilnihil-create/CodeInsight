#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push push_back
const int N = 1e5 + 7;
int n;
vector <int> g[N];
vector <int> path, cur;
bool inp[N];
void dfs(int u, int p) {
    cur.push_back(u);
    if (u == n) path = cur;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }   
    }
    cur.pop_back(); 
}   
int jfs(int u, int p) {
    int ans = 1;
    for (int v : g[u]) {
        if (v != p && !inp[v]) ans += jfs(v, u);
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; g[u].push(v); g[v].push(u);
    }   
    dfs(1, 1);
    for (int e : path) inp[e] = 1;
    int m = (path.size() + 1) >> 1;
    int f = 0, s = 0;
    for (int i = 0; i < m; ++i) {
        f += jfs(path[i], path[i]);
    }   
    for (int i = m; i < (int)path.size(); ++i) {
        s += jfs(path[i], path[i]);
    }   
    if (f > s) cout << "Fennec\n";
    else cout << "Snuke\n";
}   