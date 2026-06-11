#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<vector<int>>>dp(55,vector<vector<int>>(55,vector<int>(55*55,0)));
// dp[i][j][k] i番目以内でj個使ってkを作る

signed main(void){
    int n,a; cin >> n >>a;
    vector<int>x(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i];
    dp[1][1][x[1]]++;
    for(int i=2;i<=n;i++){
        dp[i][1][x[i]]++;
        for(int j=1;j<=i;j++){
            for(int k=0;k<=50*50;k++){
                dp[i][j][k] += dp[i-1][j][k];
                if(k+x[i] < dp[i][j].size()) dp[i][j][k+x[i]] += dp[i-1][j-1][k];
            }
        }
    }
    
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         for(int k=0;k<30;k++){
    //             cout << dp[i][j][k] << ' ';
    //         }cout << endl;
    //     }cout << endl;
    // }cout << endl;
    
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        
        ans += dp[n][i][a*i];
    }
    cout << ans << endl;
    return 0;
}