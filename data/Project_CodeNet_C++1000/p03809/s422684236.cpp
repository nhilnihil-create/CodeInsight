#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[N], val = 1;
vector <int> g[N];

int dfs(int v, int p = 0) {
    int sum = 0, mx = 0;
    for (int u : g[v]) if (u != p) {
        int w = dfs(u, v);
        mx = max(mx, w), sum += w;
    }
    int res = a[v] - sum;
    if (res < 0 || (p == 0 && res != 0)) val = 0;
    if (g[v].size() > 1 && a[v] < max(mx, res)*2) val = 0;
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1) root = i, a[i]<<=1;
        else res += a[i];
    }
    dfs(root);
    if (res % 2 == 1) val = 0;
    if (root == 0) val = (a[1] == a[2]);
    cout << (val ? "YES\n" : "NO\n");

    return 0;
}
