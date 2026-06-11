#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    cin >> n >> a;

    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    // dp[i][j][k] = up to i-th card, used j cards, sum k
    vector<vector<vector<long long int>>> dp(51,vector<vector<long long int>>(51, vector<long long int>(2501)));
    dp[0][0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<2501; k++){
                dp[i+1][j][k] += dp[i][j][k];
                if(k - x[i] >= 0) dp[i+1][j+1][k] += dp[i][j][k - x[i]];
                //if(dp[i][j][k] != 0) cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
            }
        }
    }

    long long int ans = 0;
    for(int i=1; i<=n; i++){
        ans += dp[n][i][i * a];
    }
    cout << ans << endl;
    return 0;
}