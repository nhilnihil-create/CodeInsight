#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

const ll MAXN = 40;
const ll SUMMAX = 400;
const ll INF = 1000000;
ll dp[MAXN + 1][SUMMAX + 1][SUMMAX + 1];

int main()
{
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    REP(i, N) cin >> a[i] >> b[i] >> c[i];

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= SUMMAX; ++j)
        {
            for (int k = 0; k <= SUMMAX; ++k)
            {
                if (j == 0 && k == 0) dp[i][j][k] = 0;
                else dp[i][j][k] = INF;
            }
        }
    }
    for (ll i = 1; i <= N; ++i)
    {
        for (ll j = 0; j <= SUMMAX; ++j)
        {
            for (ll k = 0; k <= SUMMAX; ++k)
            {
                if (j - a[i - 1] >= 0 && k - b[i - 1] >= 0)
                {
                    if (dp[i - 1][j - a[i - 1]][k - b[i - 1]] != INF)
                    {
                        dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
                        dp[i][j - a[i - 1]][k - b[i - 1]] = min(dp[i][j - a[i - 1]][k - b[i - 1]], dp[i - 1][j - a[i - 1]][k - b[i - 1]]);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int j = 1; j <= SUMMAX; ++j)
    {
        for (int k = 1; k <= SUMMAX; ++k)
        {
            if (j * Mb == k * Ma)
            {
                if (dp[N][j][k] != INF)
                {
                    ans = min(ans, dp[N][j][k]);
                }
            }
        }
    }
        
    if (ans != INF) cout << ans << endl;
    else cout << "-1" << endl;
}
