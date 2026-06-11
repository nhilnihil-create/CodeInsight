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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, p;
    cin >> n >> p;
    vector<ll> dp(2, 0);
    dp[0] = 1;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 2 == 1) {
            ll tmp = dp[0] + dp[1];
            dp[1] += dp[0];
            dp[0] = tmp;
        }
        else {
            dp[0] *= 2;
            dp[1] *= 2;
        }
    }
    cout << dp[p] << endl;
    return 0;
}
