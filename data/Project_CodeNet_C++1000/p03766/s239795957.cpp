#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
ll dp[1100100], sum[1100100];

int main(){
    ll n; cin >> n;
    dp[0] = 1; dp[1] = 1;
    sum[0] = 0; sum[1] = 1; sum[2] = 2;
    for (ll i = 2; i < n; i++){
        dp[i] = (dp[i-1] + sum[i-2]) % MOD;
        sum[i+1] = sum[i] + dp[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if (i <= n-3) ans += dp[i] * ( (n-1)*(n-1) % MOD + i+2 ) % MOD;
        else if (i == n-2) ans += dp[i] * ( (n-1)*n % MOD ) % MOD;
        else if (i == n-1) ans += dp[i] * n % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}