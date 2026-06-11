#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(-1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
#define smaller_queue_p  priority_queue <pll, vector<pll>, greater<pll> >
//------------------------------------------------------

ll bin_pow_mod(ll x, ll y) { //x^y mod
    if (x == 0) return 0;
    ll prod = 1;
    while (y > 0) {
        if (y % 2 == 1) prod = (prod * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return prod % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll l = s.length();
    ll dp[n + 1][n + 2] = {};
    dp[0][0] = 1LL;

    REP(i, 1, n + 1) REP(j, 0, n + 1) {
        if (j == 0) dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        else dp[i][j] = (2 * dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
    }

    ll ans = dp[n][l];
    ll inv = bin_pow_mod(2, MOD - 2);
    rep(i, l) ans = (ans * inv) % MOD;
    cout << ans << endl;

    return 0;
}
