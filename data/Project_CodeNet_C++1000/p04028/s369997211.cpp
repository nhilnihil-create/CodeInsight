#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll pot(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b % 2 == 1)
        return a * pot(a, b - 1) % MOD;
    ll x = pot(a, b / 2);
    return x * x % MOD;
}

ll inv(ll a)
{
    return pot(a, MOD - 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    string nap;
    cin >> n >> nap;
    int l = nap.size();
    if (n < l)
    {
        cout << "0";
        return 0;
    }
    vector< vector<ll> > dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + 2 * dp[i - 1][j - 1]) % MOD;
            if (j + 1 <= n && j + 1 <= i - 1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            if (j == 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }
    ll odp = dp[n][l] * inv(pot(2, l)) % MOD;
    cout << odp;
    return 0;
}
