#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,A;
    cin >> N >> A;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<vector<ll> > dp(51,vector<ll> (2501));
    rep(i,51){
        rep(j,2501){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    rep(i,N){
        for (ll j = 49; j >= 0; j--){
            for (ll k = 2450; k >= 0; k--){
                dp[j + 1][k + vec[i]] += dp[j][k];
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= 50; i++){
        ans += dp[i][i * A];
    }
    cout << ans << endl;
}

