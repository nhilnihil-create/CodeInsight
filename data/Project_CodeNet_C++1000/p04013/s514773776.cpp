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
    rep(i,  n){
        cin >> x[i];
        x[i] -= a;
    }

    ll dp[n+1][2*a*n+1] = {};
    dp[0][n*a] = 1;
    rep(i, n)rep(j, 2*a*n){
        if(j - x[i] < 0 || j - x[i] > 2*a*n){
            dp[i+1][j+1] = dp[i][j+1];
        }
        else dp[i+1][j+1] = dp[i][j+1] + dp[i][j+1-x[i]];
    }

    cout << dp[n][a*n] - 1 << endl;
}
