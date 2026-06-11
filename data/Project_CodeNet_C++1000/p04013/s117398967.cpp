#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll dp[51][51][2501];

int main(){
    ll N, A;
    cin >> N >> A;
    vector<ll> x(N+1);
    rep(i, 1, N+1) cin >> x[i];

    ll X = max(A, *max_element(x.begin(), x.end()));
    rep(j, 0, 51){
        rep(k, 0, 51){
            rep(s, 0, 2501) dp[j][k][s] = 0;
        }
    }
    dp[0][0][0] = 1;

    for(ll j = 1; j <= N; j++){
        for(ll k = 0; k <= N; k++){
            for(ll s = 0; s <= k*X; s++){
                if(s < x[j]){
                    dp[j][k][s] = dp[j-1][k][s];
                }else if(k > 0 && s >= x[j]){
                    dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j]];
                }
            }
        }
    }

    ll ans = 0;
    rep(k, 1, N+1) ans += dp[N][k][k*A];
    cout << ans << endl;
    return 0;
}