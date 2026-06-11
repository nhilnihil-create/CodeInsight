#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, p;
    cin >> n >> p;

    vector<vector<ll>> dp(51, vector<ll>(2, 0));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(a % 2 == 0){
            dp[i+1][0] = 2*dp[i][0];
            dp[i+1][1] = 2*dp[i][1];
        }
        else{
            dp[i+1][0] = dp[i][1] + dp[i][0];
            dp[i+1][1] = dp[i][0] + dp[i][1];  
        }
    }
    cout << dp[n][p];
}