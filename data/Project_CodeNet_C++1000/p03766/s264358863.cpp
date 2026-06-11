#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

long long n;
long long dp[1500000];
long long s = 0;

int main()
{
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    s = 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (s + MOD - dp[i - 2]) % MOD;
        s = (dp[i] + s) % MOD;
        //cout << dp[i] << "\n";
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        ans = (ans + ((n - 1) * (n - 1) + i + 1) % MOD * dp[i]) % MOD;
    }
    ans = (ans + dp[n - 1] * (n - 1)) % MOD;
    ans = (ans + dp[n])  % MOD;
    cout << ans % MOD;
}
