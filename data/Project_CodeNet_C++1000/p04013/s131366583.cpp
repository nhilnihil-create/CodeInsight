#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
const int MX = 1e6;
const int inf = 1e9;
//const int mod = 1e9+7;
using ll = long long;
const int mod = 1000000007;

ll ans = 0;
int n;
int a;
int x[MX];
ll dp[52][52][3000];
signed main(){
    cin >> n >> a;
    rep(i,n) {
        cin >> x[i+1];
        //cout << x[i+1] << endl;
    }

    dp[0][0][0]=1;
    FOR(j,1,n+1) {
        rep(k,j+1) {
            rep(s,3000) {
                if(k-1>=0 && s-x[j]>=0) dp[j][k][s]= dp[j-1][k-1][s-x[j]]+dp[j-1][k][s];
                else dp[j][k][s] = dp[j-1][k][s];
                
            }
        }
        //cout << j <<" " <<dp[j][1][7] << endl;
    }
    FOR(i,1,n+1) ans += dp[n][i][i*a];
    //cout << dp[1][1][7] << endl;
    cout << ans << endl;

    return 0;
}
