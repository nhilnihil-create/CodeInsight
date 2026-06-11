#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int dp[45][405][405];
int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,45){
        rep(j,405){
            rep(k,405){
                dp[i][j][k] = 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 400; j++){
            for(int k = 0; k <= 400; k++){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
            }
        }
    }
    int ans = 1e9;
    for(int j = 0; j <= 400; j++){
        for(int k = 0; k <= 400; k++){
            if(j == 0 && k == 0) continue;
            if(j*mb == k*ma && dp[n][j][k] != 1e9) ans = min(ans, dp[n][j][k]);
        }
    }
    if(ans == 1e9) cout << "-1" << endl;
    else cout << ans << endl;
}