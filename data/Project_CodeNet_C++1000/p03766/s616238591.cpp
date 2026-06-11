#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int n, dp[1000005], res[1000005], sum, ans;

signed main(){
    cin >> n;
    sum = 2;
    res[0] = res[1] = 1;
    for(int i = 2; i <= n; i++){
        res[i] = (sum - res[i - 2] + mod) % mod;
        sum = (sum + res[i]) % mod;
        dp[i] = ((res[i - 2] * (n - 1)) % mod * (n - 1)) % mod;
        dp[i] = (dp[i] + (res[i - 2] * (n - 1))) % mod;                             
        ans = (ans + dp[i]) % mod;
    }
    ans = (ans + (res[n - 1] * (n - 1))) % mod;
    cout << ans + 1;
}