#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 20

signed main() {
    int n;
    cin >> n;
    int x[n];
    rep(i, n) {
        cin >> x[i];
    }
    int l, q;
    cin >> l >> q;
    int a[q], b[q];
    rep(i, q) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    int dp[n][MAX + 1];
    rep(i, n) {
        dp[i][0] = upper_bound(x, x + n, x[i] + l) - x - 1;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i + 1] = dp[dp[j][i]][i];
        }
    }
    rep(i, q) {
        int ans = 0, cur = a[i];
        for (int j = MAX; j >= 0; j--) {
            if (dp[cur][j] < b[i]) {
                cur = dp[cur][j];
                ans += 1 << j;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}