#include <bits/stdc++.h>
using namespace std;

int main(){

    int N,P;
    cin >> N >> P;
    vector<vector<long long>> dp(N+1,vector<long long>(2));
    dp[0][0] = 1;//0個の整数の和は0
    dp[0][1] = 0;

    for(int i=1;i<=N;i++){
        int A;
        cin >> A;
        
        if (A%2 == 0){
            dp[i][0] = dp[i-1][0]*2;
            dp[i][1] = dp[i-1][1]*2;
        }else{
            dp[i][0] = dp[i-1][1] + dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
        }
    }
  
    cout << dp[N][P] << endl;
  
}