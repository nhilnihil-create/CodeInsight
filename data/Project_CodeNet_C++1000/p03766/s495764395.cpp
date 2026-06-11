#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[2000005];

int main()
{
    ll n;
    cin >> n;
    dp[0] = 1;
    ll s = 0;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(i >= 3) s = (s + dp[i - 3]) % MOD;
        dp[i] = (s + dp[i - 1]) % MOD;
        ans = (ans + dp[i - 1] * (n - 1)) % MOD;
        if(i >= 2) ans = (ans + dp[i - 2] * (n - 1) % MOD * (n - 2)) % MOD;
    }
    ans = (ans + dp[n - 1] * n + dp[n - 2] * (n - 1) % MOD * (n - 2)) % MOD;
    for(int i = n; i <= n * 2 - 1; i++){
        if(i >= 3 && i <= n + 1) s = (s + dp[i - 3]) % MOD;
        if(i >= n + 2) s = (s + MOD - dp[i - (n + 2)]) % MOD;
        ans = (ans + s) % MOD;
    }
    cout << ans << endl;
}