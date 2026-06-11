#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MAXN = 2e5+5;
long long dp[MAXN][5];

int main()
{
    long long n;
    cin>>n;
    long long num;
    cin>>num;
    dp[0][0] = num;
    dp[0][1] = -1e18;
    dp[0][2] = -1e18;
    
    for(long long i=1;i<n;i++){
        long long x;
        char y;
        
        cin>>y;
        cin>>x;
        if(y == '+'){
            dp[i][0] = dp[i-1][0]+x;
            dp[i][0] = max(dp[i][0],dp[i-1][1]-x);
            dp[i][1] = dp[i-1][1]-x;
            dp[i][1] = max(dp[i][1],dp[i-1][2]+x);
            dp[i][2] = dp[i-1][2]+x;
        }else{
           
            dp[i][0] = dp[i-1][0]-x;
            dp[i][0] = max(dp[i][0],dp[i-1][1]+x);
            dp[i][1] = dp[i-1][1]+x;
            dp[i][1] = max(dp[i][1],dp[i-1][0]-x);
            dp[i][1] = max(dp[i][1],dp[i-1][2]-x);
            dp[i][2] = dp[i-1][2]-x;
            dp[i][2] = max(dp[i][2],dp[i-1][1]+x);
        }
     //   cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
}