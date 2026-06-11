#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    constexpr int INF = 1e9 + 6;
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(401, vector<int>(401, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        for (int j = 0; j < 401; j++) {
            for (int k = 0; k < 401; k++) {
                if (dp[i][j][k] == INF) continue;
                dp[i + 1][j + a][k + b] = min(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    int ans = INF;
    for (int i = 1; i < 401; i++) {
        if (ma * i <= 400 && mb * i <= 400) {
            ans = min(ans, dp[n][ma * i][mb * i]);
        }
        else {
            break;
        }
    }
    if (ans == INF) puts("-1");
    else cout << ans << endl;
    return 0;
}