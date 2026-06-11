#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j,k;
    ll n,ma,mb;
    cin >> n >> ma >> mb;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }
    
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(401,vector<ll>(401,5000)));

    dp[0][0][0] = 0;

    for(i = 0;i < n;++i){
        rep(j,401){
            rep(k,401){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if(j >= a.at(i) && k >= b.at(i)) dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j - a.at(i)][k - b.at(i)] + c.at(i));
            }
        }
    }
    ll ans = 1e14;
    for(i = 1;i <= 400;++i){
        if(i*ma > 400 || i*mb > 400) break;
        ans = min(ans, dp[n][i*ma][i*mb]);
    }
    if(ans == 5000) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}