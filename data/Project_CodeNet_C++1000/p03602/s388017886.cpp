#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, linf));
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (k == i || k == j) continue;
                dp[i][j] = min(dp[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] < dp[i][j]) ans += a[i][j];
            if (a[i][j] > dp[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
