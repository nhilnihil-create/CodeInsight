#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2007;

vector <int> g[N];
int dist[N][N];

void dfs(int u, int p, int start, int d) {
    dist[start][u] = d;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u, start, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) dfs(i, -1, i, 0);
    int res = n + 1;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] * 2 > k) {
                ++cur;
            }
        }
        res = min(res, cur);
    }
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (min(dist[u][i], dist[v][i]) * 2 >= k) {
                    ++cur;
                }
            }
            res = min(res, cur);
        }
    }
    cout << res << '\n';
}