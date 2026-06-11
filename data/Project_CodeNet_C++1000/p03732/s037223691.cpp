#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i,N) cin >> w[i] >> v[i];
    ll w0 = w[0];
    vector<vector<ll> > dp(N + 1, vector<ll> (305));
    rep(i,N + 1){
        rep(j, 305){
            dp[i][j] = 0;
        }
    }
    for (ll i = 1; i <= N; i++){
        for (ll k = N; k >= 1; k--){
            for (ll j = 0; j <= 300; j++){
                dp[k][j + (w[i - 1] - w0)] = max(dp[k][j + (w[i - 1] - w0)], dp[k - 1][j] + v[i - 1]);
            }
        }
    }
    ll ans = 0;
    rep(i,N + 1){
        rep(j, 305){
            if (w0 * i + j <= W) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

