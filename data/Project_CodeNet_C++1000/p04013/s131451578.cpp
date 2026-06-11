#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll N, A;
    cin >> N >> A;

    ll x[N + 1];
    ll max_x = 0;
    for (ll i = 1; i <= N; i++)
    {
        cin >> x[i];
        if (x[i] >= max_x)
            max_x = x[i];
    }
    if (A >= max_x)
        max_x = A;

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N * max_x + 1, 0)));
    dp[0][0][0] = 1;

    for (ll j = 1; j <= N; j++)
    {
        for (ll k = 0; k <= N; k++)
        {
            for (ll s = 0; s <= N * max_x; s++)
            {
                dp[j][k][s] += dp[j - 1][k][s];
                if (s >= x[j] && k >= 1)
                {
                    dp[j][k][s] += dp[j - 1][k - 1][s - x[j]];
                }
            }
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++)
    {
        ans += dp[N][i][i * A];
    }

    cout << ans << endl;

    return 0;
}
