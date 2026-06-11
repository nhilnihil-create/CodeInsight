#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    int n, a;
    cin >> n >> a;

    ll x[n];
    rep(i,  n)cin >> x[i];

    ll dp[n+1][n+1][n*a+1];
    rep(i, n+1)rep(j, n+1)rep(k, n*a+1)dp[i][j][k] = 0;

    dp[0][0][0] = 1;
    rep(i, n)rep(j, n+1)rep(k, n*a+1){
        if(k - x[i] < 0)dp[i+1][j][k] = dp[i][j][k];
        else if(j > 0)dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += dp[n][i][a*i];
    }


    cout << ans << endl;
}
