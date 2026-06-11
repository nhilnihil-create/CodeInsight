#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

constexpr ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    vector<ll> dp(n + 1);
    dp[n] = n;
    ll sum = dp[n];
    for (int i = n - 1; i > 0; i--) {
        //next is 1
        dp[i] = sum;
        if (i + 2 <= n)dp[i] += MOD - dp[i + 2];
        dp[i] += min((int) n - 1, i + 1), dp[i] %= MOD;
        //next is not 1
        dp[i] += (n - 1) * (n - 1), dp[i] %= MOD;
        sum += dp[i], sum %= MOD;
    }

    cout << dp[1] << endl;
    return 0;
}