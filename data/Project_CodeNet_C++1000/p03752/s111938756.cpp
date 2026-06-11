#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    ll INF = 1e14;
    int n,k;
    cin >> n >> k;
    ve<ll> a(n);
    rep(i,n) cin >> a[i];
    ve<ve<ll>> dp(n,ve<ll>(k+1, INF));
    ve<ve<ll>> max(n,ve<ll>(k+1,INF));
    dp[0][0] = 0;
    max[0][0] = a[0];
    for(int i = 1; i < n; i++){
        rep(j,k){
            if(a[i]>max[i-1][j]){
                max[i][j+1] = a[i];
                dp[i][j+1] = min(dp[i-1][j+1],dp[i-1][j]);
                dp[i][j] = dp[i-1][j];
            }else{
                max[i][j+1] = max[i-1][j]+1;
                dp[i][j+1] = min(dp[i-1][j+1],dp[i-1][j] + max[i-1][j]+1-a[i]);
                max[i][j] = min(max[i][j],max[i-1][j]);
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
            }
        }
    }
    cout << dp[n-1][k-1] <<endl;
    return 0;
}