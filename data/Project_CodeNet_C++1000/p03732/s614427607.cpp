#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];

    map<ll, ll> dp[N + 1];
    dp[0][0] = 0;
    for (ll i = 1; i <= N; ++i)
    {
        for (ll j = 0; j < i; ++j)
        {
            for (ll k = w[0] * j; k <= w[0] * j + 3 * j; ++k)
            {
                if (dp[i - 1].find(k) != dp[i - 1].end())
                {
                    if (dp[i - 1].find(k + w[i - 1]) != dp[i - 1].end())
                    {
                        dp[i][k + w[i - 1]] = max(dp[i - 1][k + w[i - 1]], dp[i - 1][k] + v[i - 1]);
                    }
                    else
                    {
                        dp[i][k + w[i - 1]] = dp[i - 1][k] + v[i - 1];
                    }

                    if (dp[i].find(k) == dp[i].end())
                    {
                        dp[i][k] = dp[i - 1][k];
                    }
                }
            }
        }
    }
    ll ans = 0;
    REPV(it, dp[N])
    {
        if (it->first <= W)
        {
            ans = max(ans, it->second);
        }
    }

    cout << ans << endl;
}
