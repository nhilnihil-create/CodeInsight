#include <bits/stdc++.h>

using namespace std;

#define N 2000
#define pb push_back

int n, k, d[N + 5], f[N + 5], ans = 0x3f3f3f3f;
vector<int> G[N + 5];

void dp(int u, int fa) {
    f[u] = 0;
    for (auto v : G[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dp(v, u);
        f[u] += f[v];
    }
    f[u] += d[u] > k / 2;
}

int main() {
    cin >> n >> k;
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        G[x].pb(y), G[y].pb(x);
    }
    if (k & 1) {
        for (int i = 1; i <= n; ++i)
            for (auto v : G[i]) {
                d[i] = 0, d[v] = 0;
                dp(i, v), dp(v, i);
                ans = min(ans, f[i] + f[v]);
            }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            d[i] = 0;
            dp(i, 0);
            ans = min(ans, f[i]);
        }
    }
    cout << ans << endl;
    return 0;
}