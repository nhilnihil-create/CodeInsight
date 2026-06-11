#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef pair<ll, ll> PLL;

ll dp[110][110][500];

signed main() {
    // dp[i][j][k]: i(1~N)番目までのアイテムを使い、重さが w_0 *j + k のときの最大の価値
    rep(i,0,110) rep(j,0,110) rep(k,0,500) dp[i][j][k]=-1;

    ll N, W;
    cin>>N>>W;
    vector<ll> w(N+1),v(N+1);
    rep(i,1,N+1)
        cin>>w[i]>>v[i];
    
    dp[0][0][0]=0;
    
    rep(i,1,N+1) rep(j,0,110) rep(k,0,500) {
        if (dp[i-1][j][k]!=-1){
            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
            // printf("i=%d w=%d -> dp=%d\n", i, w[1]*j+k, dp[i][j][k]);

            dp[i][j+1][k + w[i] - w[1] ] = max(dp[i][j+1][k + w[i] - w[1] ],  dp[i-1][j][k] + v[i]);
            // printf("i=%d w=%d -> dp=%d\n", i, w[1]*(j+1) + k+w[i]-w[1],dp[i][j+1][k + w[i] - w[1] ]);
        }
    }
    
    ll ans = 0;
    rep(j,0,110) rep(k,0,500) {
        if (w[1]*j + k <= W){
            ans = max(ans, dp[N][j][k]);
        }
    }
    cout<<ans<<endl;


    return 0;
}
