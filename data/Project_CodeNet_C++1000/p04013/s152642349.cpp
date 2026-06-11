#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n, a; cin >> n >> a;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll mx = *max_element(all(x));
    ll dp[n+10][n+10][mx * n + 10];
    rep(i, n + 1) {
        rep(j, n + 1) {
            rep(k, mx * n + 1) {
                dp[i][j][k] = 0;
            }
        }
    }

    rep(j, n + 1 ) {
        rep(k, n + 1) {
            rep(s, mx * n + 1) {
                if (j == 0 && k == 0 && s == 0) dp[j][k][s] = 1;
                else if (j >= 1 && s < x[j-1]) dp[j][k][s] = dp[j-1][k][s];
                else if (j >= 1 && k >= 1 && s >= x[j-1]) dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]];
                else dp[j][k][s] = 0;
            }
        }
    }

    ll count = 0;
    for (size_t i = 1; i <= n; i++) {
        count += dp[n][i][i * a];
    }
    cout << count << endl;
    return 0;
}