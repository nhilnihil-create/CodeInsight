#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int const INF = 100000000;
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a[n], b[n], c[n];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    int dp[n+1][401][401];
    rep(i, n + 1)rep(j, 401)rep(k, 401) dp[i][j][k] = INF;
    rep(i, n + 1) dp[i][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 400; j++){
            for(int k = 1; k <= 400; k++){
                if(j >= a[i-1] && k >= b[i-1]){
                    dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-a[i-1]][k-b[i-1]] + c[i-1]);
                }else{
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    int ans = INF;
    for(int i = 1; i * ma <= 400 && i * mb <= 400; i++){
        ans = min(ans, dp[n][i*ma][i*mb]);
    }
    // rep(i, 6){
    //     rep(j, 6){
    //         cout << dp[n][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}