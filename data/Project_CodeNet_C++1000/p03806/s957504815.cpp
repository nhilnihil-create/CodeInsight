#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, Ma, Mb, a[50], b[50], c[50];
ll dp[50][401][401];

signed main(){
    cin >> N >> Ma >> Mb;
    REP(i, N) cin >> a[i] >> b[i] >> c[i];
    REP(i, N + 1) REP(j, 401) REP(k, 401) dp[i][j][k] = LONG_LONG_MAX / 2;
    dp[0][0][0] = 0;
    REP(i, N){
        REP(j, 401){
            REP(k, 401){
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if(j + a[i] > 400 || k + b[i] > 400) continue;
                dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
            }
        }
    }
    ll ans = LONG_LONG_MAX / 2;
    FOR(i, 1, 401){
        FOR(j, 1, 401){
            if(i * Mb != j * Ma) continue;
            ans = min(ans, dp[N][i][j]);
        }
    }
    if(ans == LONG_LONG_MAX / 2) PRINT("-1"); 
    else PRINT(ans);
    return 0;
}