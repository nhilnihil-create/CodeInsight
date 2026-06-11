#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll dp[50][500][500];
const ll INF = 1e18;

void init(){
    rep(i, 0, 50) rep(j, 0, 500) rep(k, 0, 500) dp[i][j][k] = INF;
}

int main(){

    // input
    ll n, ma, mb;
    cin >> n >> ma >> mb;
    vector<ll> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];

    // dp
    init();
    dp[0][0][0] = 0;
    rep(i, 0, n){
        rep(j, 0, 450){
            if(j + a[i] >= 450) continue;
            rep(k, 0, 450){
                if(k + b[i] >= 450) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
            }
        }
    }

    // search ans
    ll ans = INF;
    rep(j, 1, 450){
        if(j % ma != 0) continue;
        rep(k, 1, 450){
            if(k % mb != 0) continue;
            if(j / ma == k / mb) ans = min(ans, dp[n][j][k]);
        }
    }

    // output
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}