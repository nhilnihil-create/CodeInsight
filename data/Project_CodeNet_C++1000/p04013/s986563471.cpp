#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int W_MAX = 3000;

ll dp[55][W_MAX][55];

int main() {
    int n, a;
    cin >> n >> a;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) dp[i][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int w = 0; w < W_MAX; w++) {
                if (w >= x[i]) dp[i + 1][w][j] += dp[i][w - x[i]][j - 1];
                dp[i + 1][w][j] += dp[i][w][j];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i * a][i];
    }
    cout << ans << endl;
}