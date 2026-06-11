#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e6+5;
const long long MOD = 1e9+7;
long long dp[MAXN];
long long pref[MAXN];
int main(){
    long long n;
    cin>>n;
    dp[1] = n;
    pref[1] = n;
    dp[2] = 1LL*n*n;
    pref[2] = dp[1]+dp[2];
    for(long long i=3;i<=n;i++){
        dp[i] = dp[i-1];
        dp[i]+=1LL*(n-1)*(n-1);
        dp[i]%=MOD;
        dp[i]+=pref[i-3];
        dp[i]%=MOD;
        dp[i]+=(n-i+2);
        dp[i]%=MOD;
        pref[i] = pref[i-1]+dp[i];
        pref[i]%=MOD;

    }
    cout<<dp[n]<<endl;
}