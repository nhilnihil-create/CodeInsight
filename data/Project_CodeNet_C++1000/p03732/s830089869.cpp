#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<bool>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i)
        cin >> w[i] >> v[i];
    int ma = W / w[0];

    static int dp[103][103][303];
    for (int i = 0; i < N; ++i) {
        int tmp = w[i] - w[0];
        for (int j = 0; j <= min(i, ma); ++j) {
            for (int k = 0; k <= 300; ++k) {
                if (k - tmp >= 0) {
                    dp[i + 1][j + 1][k] = max(dp[i][j][k - tmp] + v[i], dp[i][j][k]);
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j + 1][k]);
                } else
                    dp[i + 1][j + 1][k] = dp[i][j + 1][k];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= ma; ++i)
        ans = max(ans, dp[N][i][min(W - w[0] * i, 300)]);
    cout << ans << endl;
    return 0;
}
