#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int32_t main() {
    int n;
    cin>>n;
    int dp[n+5];
    dp[1] = n;
    dp[2] = n*n;
    int ps = dp[1]+dp[2];
    for(int i=3; i<=n; i++){
        dp[i] = ps - dp[i-2] + ((n-1)*(n-1)) + (n-i+2);
        dp[i] %= MOD;
        if(dp[i] < 0) dp[i]+=MOD;
        ps+=dp[i];
        ps%=MOD;
        if(ps<0) ps+=MOD;
    }
    cout<<dp[n];
}