#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9+7;
const long long MAXN = 1e5+5;
long long arr[MAXN];
long long arr2[MAXN];
long long dp[MAXN];
long long dp2[MAXN];
int main(){
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[1] = arr[2]-arr[1];
     dp[1]%=MOD;
    for(long long i=2;i<n;i++){
        long long diff= arr[i+1]-arr[i];
        dp[i] = (1LL*i*diff)+dp[i-1];
        dp[i]%=MOD;
    }
   
    for(long long i=1;i<=m;i++){
        cin>>arr[i];
    }
    dp2[1] = arr[2]-arr[1];
    dp2[1]%=MOD;
    for(long long i=2;i<m;i++){
        long long diff= arr[i+1]-arr[i];
        dp2[i] = (1LL*i*diff)+dp2[i-1];
        dp2[i]%=MOD;
    }
    for(long long i=1;i<m-1;i++){
        dp2[m-1]+=dp2[i];
        dp2[m-1]%=MOD;
    }
    for(long long i=1;i<n-1;i++){
        dp[n-1]+=dp[i];
        dp[n-1]%=MOD;
    }
    cout<<(1LL*dp2[m-1]*dp[n-1])%MOD<<endl;
}