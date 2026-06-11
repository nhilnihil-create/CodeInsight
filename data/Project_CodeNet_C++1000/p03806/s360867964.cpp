#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1ll << 60;
static const ll MOD = 1e9 + 7;

ll N, Ma, Mb, dp[51][510][510];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    rep(i, N) { cin >> a[i] >> b[i] >> c[i]; }
    rep(i, 51)
    {
        rep(j, 510)
        {
            rep(k, 510)
            {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    rep(i, N)
    {
        rep(wa, 500)
        {
            rep(wb, 500)
            {
                if (dp[i][wa][wb] >= INF) {
                    continue;
                }
                dp[i + 1][wa][wb] = min(dp[i + 1][wa][wb], dp[i][wa][wb]);
                dp[i + 1][wa + a[i]][wb + b[i]] = min(dp[i + 1][wa + a[i]][wb + b[i]], dp[i][wa][wb] + c[i]);
            }
        }
    }
    ll res = INF;
    for (int wa = 1; wa < 500; ++wa) {
        for (int wb = 1; wb < 500; ++wb) {
            if (wa * Mb != wb * Ma) {
                continue;
            }
            res = min(res, dp[N][wa][wb]);
        }
    }
    if (res != INF) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}