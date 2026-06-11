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
    int x[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    x[0] = x[1] - 1;
    x[n + 1] = x[n] + 1;
    n += 2;
    int l, q;
    cin >> l >> q;
    int a[q], b[q];
    rep(i, q) {
        cin >> a[i] >> b[i];
    }
    int dp[n][MAX + 1], dpr[n][MAX + 1];
    rep(i, n) {
        dp[i][0] = upper_bound(x, x + n, x[i] + l) - x - 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        dpr[i][0] = lower_bound(x, x + n, x[i] - l) - x;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i + 1] = dp[dp[j][i]][i];
        }
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < n; j++) {
            dpr[j][i + 1] = dpr[dpr[j][i]][i];
        }
    }
    rep(i, q) {
        int ans = 0;
        int cur = a[i];
        if (a[i] < b[i]) {
            while (cur < b[i]) {
                int j;
                for (j = 0; j <= MAX; j++) {
                    if (b[i] < dp[cur][j]) break;
                }
                if (j) j--;
                cur = dp[cur][j];
                ans += 1 << j;
            }
        } else {
            while (b[i] < cur) {
                int j;
                for (j = 0; j <= MAX; j++) {
                    if (dpr[cur][j] < b[i]) break;
                }
                if (j) j--;
                cur = dpr[cur][j];
                ans += 1 << j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}