#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 1000000;

int dp[41][401][401];

int main()
{
    int n, ma, mb;
    cin >> n >> ma >> mb;

    int a[n], b[n], c[n];

    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    rep(i, n + 1) rep(j, 401) rep(k, 401) dp[i][j][k] = inf;

    dp[0][0][0] = 0;

    rep(i, n)
    {
        rep(j, 401)
        {
            rep(k, 401)
            {
                dp[i + 1][j][k] = dp[i][j][k];
                if (j - a[i] >= 0 && k - b[i] >= 0)
                    dp[i + 1][j][k] = min(dp[i][j - a[i]][k - b[i]] + c[i], dp[i][j][k]);
            }
        }
    }
    int ans = 1e7;

    for (int j = 1; j <= 400; j++)
    {
        for (int k = 1; k <= 400; k++)
        {
            if (j * mb == k * ma)
                ans = min(ans, dp[n][j][k]);
        }
    }

    OP((ans == inf ? -1 : ans));

    return 0;
}