#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n ;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<int>>dp(n, vector<int>(2));
    // dp[i][0] --> denotes the max len of the subaary including this i for increasing subaaray
    // dp[i][1] --> denotes the max len of the subaary including this i for decreasing subaarsy
    
    dp[0][0] = 1;
    dp[0][1] = 1;
     //cout << dp[0][0] << " " << dp[0][1] << endl; 
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        bool increasing = false;
        bool decreasing = false;
        if(a[i] >= a[i-1]){
            dp[i][0] += 1;
            //dp[i][1] = 0;
            increasing = true;
        }
        if(a[i] <= a[i-1]){
            dp[i][1] += 1;
            //dp[i][0] = 0;
            decreasing = true;
        }
        
        if(decreasing^increasing){
            if(decreasing)dp[i][0] = 1;
            else dp[i][1] = 1;
        }
        
        //cout << dp[i][0] << " " << dp[i][1] << endl; 
    }
    
    int start_idx = n - 1;
    int result = 0;
    while(start_idx >= 0){
        int optimal_value = max(dp[start_idx][0], dp[start_idx][1]);
        result += 1;
        start_idx -= optimal_value;
        //start_idx += 1;
        //cout << start_idx << endl;
    }
    
    cout << result << endl;


}
