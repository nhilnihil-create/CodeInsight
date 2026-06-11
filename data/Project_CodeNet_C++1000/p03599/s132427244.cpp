#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

bool check(ll e, ll sum, ll sugar) {
    return ((sugar * (100 + e)) <= (e * sum));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MIN / 2 + 1;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<ll> dp(f + 1, inf);
    dp[0] = 0;
    double per = -100;
    ll answs = 0, anss = 0;
    reps(i, 1, f + 1) {
        if ((i >= (100 * a)) && (dp[i - (100 * a)] != inf)) {
            dp[i] = max(dp[i], dp[i - (100 * a)]);
        }
        if ((i >= (100 * b)) && (dp[i - (100 * b)] != inf)) {
            dp[i] = max(dp[i], dp[i - (100 * b)]);
        }
        if ((i >= c) && (dp[i - c] != inf) && (check(e, i, dp[i - c] + c))) {
            dp[i] = max(dp[i], dp[i - c] + c);
        }
        if ((i >= d) && (dp[i - d] != inf) && (check(e, i, dp[i - d] + d))) {
            dp[i] = max(dp[i], dp[i - d] + d);
        }
        if (dp[i] == inf) continue;
        double tmp = (double)dp[i] / i;
        if (per < tmp) {
            per = tmp;
            answs = i;
            anss = dp[i];
        }
    }
    printf("%lld %lld\n", answs, anss);
    return 0;
}
