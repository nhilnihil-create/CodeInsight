#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, W; cin >> n >> W;
    vector <pair <int, int> > obj;
    for (int i = 0; i < n; ++ i) {
        int w, v; cin >> w >> v;
        obj.emplace_back(w, v);
    }
    vector <vector <vector <int> > > dp(n + 1, vector <vector <int> > (n + 1, vector <int> (3 * n + 1, -0x3f3f3f3f)));
    dp[0][0][0] = 0;
    auto chkmax = [&] (int & x, int y) {x = y > x ? y : x;};
    for (int i = 0; i < n; ++ i) {
        int w = obj[i].first, v = obj[i].second;
        for (int j = 0; j <= n; ++ j) {
            for (int k = 0; k <= 3 * n; ++ k) {
                if (j < n) chkmax(dp[i + 1][j + 1][k + w - obj[0].first], dp[i][j][k] + v);
                chkmax(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= 3 * n; ++ j) {
            if (1LL * i * obj[0].first + j <= W) {
                chkmax(ans, dp[n][i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}