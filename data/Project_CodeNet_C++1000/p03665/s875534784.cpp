#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll dp[110][2];

int main() {

    ll n, p; cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[0][0] = 1; //dp[0][1] = 0になっている
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 2; ++j) {
            dp[i + 1][j] += dp[i][j]; //選ばない
            dp[i + 1][(j + a[i]) % 2] += dp[i][j]; //選ぶ
        }
    }

    cout << dp[n][p] << endl;
}