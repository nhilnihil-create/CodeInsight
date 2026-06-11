#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, dp[1000008][3], lazy[1000008];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    dp[0][0] = 1;

    ll comp = 0;
    rep(i, 1, n){
        lazy[i] += lazy[i-1]; lazy[i] %= MOD;
        dp[i][0] += lazy[i]; dp[i][0] %= MOD;
        dp[i][0] += dp[i-1][0]; dp[i][0] %= MOD;
        dp[i][1] += lazy[i]; dp[i][0] %= MOD;
        dp[i][1] += dp[i-1][0]; dp[i][1] %= MOD;
        dp[i][2] += dp[i-1][1]*(n-1)%MOD; dp[i][2] %= MOD;
        dp[i][2] += dp[i-1][2]; dp[i][2] %= MOD;

        if(i+2 <= n){
            lazy[i+2] += dp[i-1][1]; lazy[i+2] %= MOD;
        }

        if(i < n){
            comp += dp[i-1][1]*i%MOD; comp %= MOD;
        }
        else{
            comp += dp[i-1][1]*(i-1)%MOD; comp %= MOD;
        }
        //print(comp)
    }

    //rep(i, 0, n)cout << dp[i][0] << dp[i][1] << dp[i][2] << endl;
    print((dp[n][0]+dp[n][1]*(n-1)%MOD+dp[n][2]*(n-1)%MOD+comp)%MOD)
    return 0;
}