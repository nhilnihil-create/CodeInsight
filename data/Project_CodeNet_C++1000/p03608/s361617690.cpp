#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)
const ll INF = 99999999999;

int main() {
    int N, M, R; cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    sort(ALL(r));
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    ll A, B, C;
    rep(i, M) {
        cin >> A >> B >> C;
        A--; B--;
        dp[A][B] = dp[B][A] = C;
    }
    rep(i, N) dp[i][i] = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = INF*1000000;
    do {
        ll cnt = 0;
        rep(i, R-1) {
            cnt += dp[r[i]][r[i+1]];
        }
        chmin(ans, cnt);
    } while(next_permutation(ALL(r)));
    cout << ans << endl;
}
