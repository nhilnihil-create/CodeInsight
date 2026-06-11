#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<vector<long long int>> dp(n+1, vector<long long int>(2));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        dp[i+1][0] = dp[i][0]; 
        dp[i+1][1] = dp[i][1];

        if(a[i] % 2 == 0){ dp[i+1][0] += dp[i][0]; dp[i+1][1] += dp[i][1]; }
        if(a[i] % 2 == 1){ dp[i+1][0] += dp[i][1]; dp[i+1][1] += dp[i][0]; }
    }
    cout << dp[n][p] << endl;
    return 0;
}