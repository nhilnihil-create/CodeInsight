#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 17;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, k;
vector<int> g[N];
pair<int, int> E[N];

bool read() {
    if (!(cin >> n >> k))
        return false;

    for (int i = 0; i < n - 1; ++i) {
        auto& u = E[i].first;
        auto& v = E[i].second;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    return true;
}

void dfs(int v, int pr, int& cnt, int h, int mxh) {
    if (h > mxh)
        return ;
    ++cnt;
    for (auto to : g[v])
        if (to != pr)
            dfs(to, v, cnt, h + 1, mxh);
}

int calc(int v, int pr, int mxh) {
    int cnt = 0;
    dfs(v, pr, cnt, 0, mxh);
    return cnt;
}

void solve() {
    auto ans = n;
    auto d = k / 2;

    for (int i = 0; i < n; ++i)
        ans = min(ans, n - calc(i, -1, d));

    d = (k - 1) / 2;

    for (int i = 0; i < n - 1; ++i)
        ans = min(ans, n - calc(E[i].first, E[i].second, d) - calc(E[i].second, E[i].first, d));

    cout << ans << '\n';
}
 
int main() {
    while (read())
        solve();
    return 0;
}