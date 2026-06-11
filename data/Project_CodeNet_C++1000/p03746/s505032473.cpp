#include <bits/stdc++.h>

#define sz(x) ((int)x.size())

using namespace std;


const int MAXN = 100 * 1000 + 23;







int n, m;
vector<int> g[MAXN];
bitset<MAXN> mark;
vector<int> d;

void dfs(int v) {
    mark[v] = true;
    d.push_back(v);
    for (auto u : g[v])
        if (!mark[u]) {
            dfs(u);
            break;
        }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v), g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (sz(g[i]) != 0) {
            dfs(i);
            break;
        }
    reverse(d.begin(), d.end());
    d.pop_back();
    for (int i = 0; i < n; i++)
        if (sz(g[i]) != 0) {
            dfs(i);
            break;
        }
    cout << d.size() << '\n';
    for (auto i : d)
        cout << i + 1 << ' ';
    return 0;
}