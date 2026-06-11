#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

struct S {
    ll a, b, c;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n, ma, mb;
    cin >> n >> ma >> mb;
    vector<S> s(n);
    ll suma = 0, sumb = 0;
    rep(i, n) {
        cin >> s[i].a >> s[i].b >> s[i].c;
        suma += s[i].a;
        sumb += s[i].b;
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(suma + 1, vector<ll>(sumb + 1, inf)));
    dp[0][0][0] = 0;
    ll ans = inf;
    rep(i, n) {
        rep(j, suma + 1) {
            rep(k, sumb + 1) {
                dp[i + 1][j][k] = dp[i][j][k];
                if ((j >= s[i].a) && (k >= s[i].b) && (dp[i][j - s[i].a][k - s[i].b] != inf)) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - s[i].a][k - s[i].b] + s[i].c);
                }
                if ((dp[i + 1][j][k] != inf) && (j != 0) && (k != 0) && (j % ma == 0) && (k % mb == 0) && ((j / ma) == (k / mb))) {
                    ans = min(ans, dp[i + 1][j][k]);
                }
            }
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}
