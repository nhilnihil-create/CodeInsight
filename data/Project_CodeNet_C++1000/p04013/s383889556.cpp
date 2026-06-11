#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

// i番目まで選んだ時、合計jになるのがいくつあるか。
ll dp[55][5000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;
    vector<ll> x(N);
    rep(i, N) {
        cin >> x[i];
        x[i] -= A;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][2500] = 1;

    rep(i, N) {
        rep(j, 5000) {
            if (dp[i][j] == 0)
                continue;
            dp[i + 1][j] += dp[i][j];
            if (j + x[i] >= 0)
                dp[i + 1][j + x[i]] += dp[i][j];
        }
    }

    ll ans = dp[N][2500] - 1;
    cout << ans << endl;
}