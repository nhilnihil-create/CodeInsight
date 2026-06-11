#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

long int dp[51][51][2501];
int main(){
    long int n, a;
    cin >> n >> a;
    long int x[n];
    rep(i, n) cin >> x[i];
    
    rep(i, n + 1)rep(k, n + 1)rep(j, 2501) dp[i][k][j] = 0;
    
    rep(i, n + 1) dp[i][0][0] = 1; 
    
    rep(i, n){
        for (int k = 0; k <= i; k++){
            for (int j = 0; j <= 2500; j++){
                if(j >= x[i]){
                    dp[i+1][k+1][j] = dp[i][k+1][j] + dp[i][k][j-x[i]];
                }else{
                    dp[i+1][k+1][j] = dp[i][k+1][j];
                }
            }   
        }
    }

    // rep(i, n + 1){
    //     rep(j, 40){
    //         cout << dp[n][i][j] << " ";
    //     }cout << endl;
    // }

    long int ans = 0;
    rep(i, n){
        ans += dp[n][i+1][(i+1)*a];
    }
    cout << ans << endl;
}
