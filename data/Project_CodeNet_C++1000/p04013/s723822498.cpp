#include <bits/stdc++.h>
using namespace std;
long long dp[55][5100];
int main(){
    int n,a;
    cin >> n >> a;
    int x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
        x[i]-=a;
    } 
    memset(dp, 0, sizeof(dp));
    dp[0][2500] = 1;  
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5000;j++){
          dp[i][j] = dp[i-1][j];
          if(0<=j-x[i-1]&&j-x[i-1]<=5000) dp[i][j]+=dp[i-1][j-x[i-1]];
        }
    }
    cout << dp[n][2500]-1 << endl;
}
