#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MAX_N = 40 + 10;
const int MAX_W = MAX_N * 10;
const int INF = 100100100100;

int dp[MAX_N][MAX_W][MAX_W];

int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    rep(i, MAX_N) rep(j, MAX_W) rep(k, MAX_W) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, N) {
        int a, b, c;
        cin >> a >> b >> c;
        rep(j, MAX_W) {
            rep(k, MAX_W) {
                dp[i + 1][j][k] = dp[i][j][k];
                if (j - a >= 0 && k - b >= 0) {
                    chmin(dp[i + 1][j][k], dp[i][j - a][k - b] + c);
                }
            }
        }
    }

    int ans = INF;
    rep(j, MAX_W) {
        rep(k, MAX_W) {
            if (j == 0 && k == 0) continue;
            if (j * Mb != k * Ma) continue;
            chmin(ans, dp[N][j][k]);
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;
}