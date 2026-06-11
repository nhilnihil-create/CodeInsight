#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll gcd(ll a, ll b) {
    while (b) {
        ll x = a, y = b;
        a = y, b = x % y;
    }
    return a;
}

int main()
{
    ll N, Ma, Mb; cin >> N >> Ma >> Mb;
    ll g = gcd(Ma, Mb);
    Ma /= g, Mb /= g;
    vector<pair<pair<ll, ll>, ll>> medicine;
    rep(i, N) {
        ll a, b, c; cin >> a >> b >> c;
        medicine.push_back({{a, b}, c});
    }
    ll dp[N+1][500][500];
    rep(i, N+1) rep(j, 500) rep(k, 500) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, 500) rep(k, 500) {
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        if (j + medicine[i].first.first < 500 && k + medicine[i].first.second < 500) dp[i+1][j+medicine[i].first.first][k+medicine[i].first.second] = 
            min(
                dp[i+1][j+medicine[i].first.first][k+medicine[i].first.second],
                dp[i][j][k] + medicine[i].second
            );
        }
    }

    ll minn = inf;
    for (ll i = 1; Ma * i < 500 && Mb * i < 500; i++) {
        minn = min(minn, dp[N][Ma*i][Mb*i]);
    }
    cout << (minn != inf ? minn : -1) << endl;
    return 0;
}