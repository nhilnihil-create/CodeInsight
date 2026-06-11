#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;


int main(){
    int n, a, X = 0;
    cin >> n >> a;
    X = a;

    vector<int> x(n);
    REP(i, n) {
        cin >> x[i];
        X = max(X, x[i]);
    }

    ll dp[n+1][n+1][n*X+1]; /* dp[i][j]; i枚目まで見て合計jになるときの通り数 */
    REP(i, n+1) REP(j, n+1) REP(k, n*X+1) dp[i][j][k] = 0;
    dp[0][0][0] = 1;

    REPN(i, 1, n+1) REP(j, n+1) REP(k, n*X+1) {
        if(k >= x[i-1] && j >= 1) {
            dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i-1]];
        } else if (k < x[i-1]) {
            dp[i][j][k] = dp[i-1][j][k];
        }
    }

    ll ans = 0;

    REPN(i, 1, n+1) {
        ans += dp[n][i][i*a];
    }

    cout << ans << endl;

    return 0;
}
