#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (auto i = 0; i < (n); i++)
#define rep2(i, s, n) for (auto i = (s); i < (n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    ll N, A; cin >> N >> A;
    vector<ll> x(N+1);
    ll tmp;
    rep2(i, 1, N+1) {
        cin >> x[i];
        x[i]-=A;
    }
    ll X = max(vmax(x), A);
    vector<vector<ll>> dp(N+1, vector<ll>(2*N*X+1));
    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= 2*N*X; j++) {
            if (i == 0 && j == N*X) dp[i][j] = 1;
            else if (i >= 1) {
                if (j-x[i] < 0 || j-x[i] > 2*N*X) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-x[i]];
            }
            else dp[i][j] = 0;
        }
    }
    cout << dp[N][N*X]-1 << endl;

}
