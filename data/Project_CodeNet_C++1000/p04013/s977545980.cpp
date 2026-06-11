#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const int MAX_N = 60;
const int MAX_X = 60;
const int MAX_V = MAX_N * MAX_X;
ll dp[MAX_N][MAX_X][MAX_V];

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    rep(i, N) cin >> x[i];

    dp[0][0][0] = 1;
    rep(i, N) {
        rep(j, N) {
            rep(k, 2550) {
                if (dp[i][j][k] == 0) continue;

                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    for (int j = 1; j <= N; j++) ans += dp[N][j][j * A];
    cout << ans << endl;
}
