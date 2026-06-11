#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> G[n];
    int a, b;
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int q;
    cin >> q;
    int v[q], d[q], c[q];
    rep(i, q) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    reverse(v, v + q);
    reverse(d, d + q);
    reverse(c, c + q);
    int ans[n] = {};
    int dp[n];
    fill(dp, dp + n, -1);
    rep(i, q) {
        if (d[i] <= dp[v[i]]) continue;
        queue<P> que;
        que.emplace(v[i], d[i] - 1);
        if (ans[v[i]] == 0) ans[v[i]] = c[i];
        dp[v[i]] = d[i];
        while (!que.empty()) {
            P p = que.front();
            que.pop();
            for (int to : G[p.first]) {
                if (p.second <= dp[to]) continue;
                que.emplace(to, p.second - 1);
                if (ans[to] == 0) ans[to] = c[i];
                dp[to] = p.second;
            }
        }
    }
    rep(v, n) {
        cout << ans[v] << endl;
    }
    return 0;
}