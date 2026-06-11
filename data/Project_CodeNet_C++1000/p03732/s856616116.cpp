#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

ll dp[110][110][500];

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N), w2(N);
    rep(i, N) cin >> w[i] >> v[i];
    rep(i, N) w2[i] = w[i] - (w[0] - 1);

    rep(i, N) {
        rep(j, N) {
            rep(k, 500) {
                if (j > 0 && dp[i][j][k] == 0) continue;

                chmax(dp[i + 1][j][k], dp[i][j][k]);
                if (k - w2[i] >= 0 && (w[0] - 1) * (j + 1) + k <= W) {
                    chmax(dp[i + 1][j + 1][k], dp[i][j][k - w2[i]] + v[i]);
                }
            }
        }
    }

//    rep(i, N + 1) {
//        cout << "i:" << i << endl;
//        rep(j, N + 1) {
//            cout << "j:" << j << endl;
//            rep(k, 10) cout << dp[i][j][k] << " ";
//            cout << endl;
//        }
//        cout << endl;
//    }

    ll ans = 0;
    rep(j, N + 1) {
        rep(k, 500) chmax(ans, dp[N][j][k]);
    }

    cout << ans << endl;
}