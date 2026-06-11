#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N, A;
    cin >> N >> A;
    vl X(N);
    rep(i, N) {
        cin >> X[i];
    }

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vl(3000)));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3000; k++) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j + 1][k + X[i]] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    rep(j, N) {
        ans += dp[N][j + 1][(j + 1) * A];
    }

    cout << ans << endl;
}