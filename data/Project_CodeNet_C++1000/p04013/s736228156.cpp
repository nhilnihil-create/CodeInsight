#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    ll n,a;
    cin >> n >> a;
    ll x[n];
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll dp[n+5][n+5][2505];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;


    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= i; j++) {
            for(ll k = 0; k <= 2500; k++) {
                if(k<x[i-1])dp[i][j][k]=dp[i-1][j][k];
                else if(j>=1 && k>=x[i-1]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
                else dp[i][j][k]=0;
            }
        }
    }



    ll ans=0;
    for(ll i = 1; i <= n; i++) {
        ll tmp=dp[n][i][i*a];
        ans+=tmp;
//        cout << i << " " << tmp << "\n";
    }
    cout << ans << "\n";

    return 0;
}