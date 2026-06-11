#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

// i番目まで選んだ時、合計jで、枚数kの時があるか
ll dp[55][2505][55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;
    vector<ll> x(N);
    rep(i, N) { cin >> x[i]; }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    rep(i, N) {
        rep(j, 2505) {
            rep(k, N) {
                // i番目を選ぶ
                dp[i + 1][j + x[i]][k + 1] += dp[i][j][k];
                // i番目を選ばない
                dp[i + 1][j][k] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    rep(j, 2505) {
        for (int k = 1; k <= N; k++) {
            if (j == k * A)
                ans += dp[N][j][k];
        }
    }

    cout << ans << endl;
}