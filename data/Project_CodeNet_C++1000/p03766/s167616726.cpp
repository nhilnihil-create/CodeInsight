#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr lint MOD = 1000000007;

int main()
{
    lint n;
    cin >> n;
    vector<lint> dp(n+1, 1);
    lint sum = 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (sum - dp[i - 2] + MOD) % MOD;
        sum = (sum + dp[i]) % MOD;
    }

    lint ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans += dp[i] * (((n-1)*(n-1) + i+1) % MOD) % MOD;
        ans %= MOD;
    }
    ans = (ans + dp[n - 1] * (n - 1)) % MOD;
    ans = (ans + dp[n]) % MOD;

    cout << ans << endl;
}
