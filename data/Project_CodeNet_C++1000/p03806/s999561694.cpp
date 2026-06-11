#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 100000;

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n + 1][10 * n + 1][10 * n + 1];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= 10 * n; j++) for (int k = 0; k <= 10 * n; k++) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j <= 10 * n; j++) for (int k = 0; k <= 10 * n; k++) {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (j + a[i] <= 10 * n && k + b[i] <= 10 * n) {
            dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
        }
    }
    int ans = inf;
    for (int j = 1; j <= 10 * n; j++) for (int k = 1; k <= 10 * n; k++) {
        if (dp[n][j][k] < ans && ma * k == mb * j) ans = dp[n][j][k];
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;;
    return 0;
}