#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 400

template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
    if (a > b) a = b;
}

signed main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a[n], b[n], c[n];
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n + 1][MAX + 1][MAX + 1];
    fill(dp[0][0], dp[n + 1][0], INF);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX; j++) {
            for (int k = 0; k <= MAX; k++) {
                chmin(dp[i + 1][j][k], dp[i][j][k]);
                if (j - a[i] < 0 || k - b[i] < 0) continue;
                chmin(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
            }
        }
    }
    int ans = INF;
    for (int i = 1; ma * i <= MAX && mb * i <= MAX; i++){
        chmin(ans, dp[n][ma * i][mb * i]);
    }
    cout << (ans != INF ? ans : -1) << endl;
    return 0;
}