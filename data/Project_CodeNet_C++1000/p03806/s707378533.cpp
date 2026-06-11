#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 1000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[41][1020][1020];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int Ma, Mb;
    cin >> Ma >> Mb;
    int a[41], b[41], c[41];
    rep(i, N) cin >> a[i] >> b[i] >> c[i];
    rep(i, 41) rep(j, 1010) rep(k, 1010) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, 1010) {
            rep(k, 1010) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]); 
                if (j + a[i] <= 1000 && k + b[i] <= 1000){
                    dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j + a[i]][k + b[i]]);
                    dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]] , dp[i][j][k] + c[i]); 
                }
            }
        }
    }
    int ans = INF;
    // rep(i, 10) {
    //     rep(j, 10) {
    //         if (dp[N][i][j] != INF)
    //             cout << dp[N][i][j] << " ";
    //         else 
    //             cout << "- ";
    //     }
    //     cout << endl;
    // }
    rep(i, 1001) {
        rep(j, 1001) {
            if (i > 0 && j > 0 && dp[N][i][j] < INF && i * Mb == j * Ma) {
                ans = min(ans, dp[N][i][j]);
            } 
        }
    }
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
