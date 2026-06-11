#include <bits/stdc++.h>
using namespace std;
#define S static
#define rep(i,n) for(ll i=0LL; i<n; ++i)
typedef long long ll;

#define MOD  (1000000007LL)

int main()
{
    ll n; cin >> n;
    string s; cin >> s;

    S ll dp[5005] = {};
    dp[0] = 1LL;

    rep (i, n) {
        S ll dp_prev[5005];
        memcpy(dp_prev, dp, sizeof(dp_prev));
        memset(dp, 0, sizeof(dp));

        rep (len, 5005) {
            if (len) dp[len] += dp_prev[len-1];
            dp[len] %= MOD;
            if (len < 5004) dp[len] += dp_prev[len+1] * 2LL;
            dp[len] %= MOD;
            if (!len) dp[len] += dp_prev[len];
            dp[len] %= MOD;
        }
    }

    cout << dp[s.size()] << endl;

    return 0;
}
