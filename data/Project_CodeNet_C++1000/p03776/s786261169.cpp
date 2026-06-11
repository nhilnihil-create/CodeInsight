/*
*
*   解説見てないお
*
*/
#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

// combination
ll comb(ll n, ll r) {
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 0; i < (ll)v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (ll j = 1; j < (ll)v.size(); j++) {
        for (ll k = 1; k < j; k++) {
            v[j][k] = v[j - 1][k - 1] + v[j - 1][k];
        }
    }
    return v[n][r];
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    REP(i, n) scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    double ans = 0;
    REP(i, a) {
        ans += double(v[n - 1 - i]) / a;
    }
    printf("%.10f\n", ans);
    auto left = lower_bound(v.begin(), v.end(), v[n - a]);
    auto right = upper_bound(v.begin(), v.end(), v[n - a]);
    // [left,right) が v[a-1]
    // 全部同じ数字
    if (right == v.end()) {
        int cnt = right - left;
        ll ans = 0;
        FOR(i, a, b + 1) {
            if (cnt >= i) {
                ans += comb(cnt, i);
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    // 異なるのがあるならa個しかえらべない
    else {
        cout << comb(right - left, right - v.begin() - n + a) << endl;
    }
    return 0;
}