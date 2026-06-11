#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 20000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[41][410][410];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    int a[41], b[41], c[41];
    rep(i, N) {
        cin >> a[i] >> b[i] >> c[i];
    }
    rep(i, 41) rep(j, 410) rep(k, 410) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, N) {
        REP(j, 0, 400) {
            REP(k, 0, 400) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if (j - a[i] >= 0 && k - b[i] >= 0) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                }
            }
        }
    }
    int ans = INF;
    REP(j, 1, 400) {
        REP(k, 1, 400) {
            if (j * Mb == k * Ma) {
                ans = min(ans, dp[N][j][k]);
            }
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
