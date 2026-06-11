#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

vector<int> g[2019];
int c, e;

int dfs(int x, int p, int d) {
    c++;
    int f = 0;
    for (int i : g[x]) if (i != p) {
        int b = 0;
        if (d) b = dfs(i, x, d - 1), f += b;
        else b = 1, f++;
        if (x == p) e = max(e, b);
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k, u, v, z = 0;
    cin >> n >> k;
    for (int i = 1; i < n; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    for (int i = 1; i <= n; i++) c = e = 0, dfs(i, i, k / 2), z = max(z, c + ((k % 2) ? e : 0));
    cout << n - z;
}
