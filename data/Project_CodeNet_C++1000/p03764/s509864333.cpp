#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

const int MOD = (int) 1e9 + 7;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ll x[n + 1], y[m + 1];
    FOR(i, 1, n + 1) cin >> x[i];
    FOR(i, 1, m + 1) cin >> y[i];

    ll xsum = 0;
    FOR(i, 1, n + 1) {
        xsum = (xsum + (i - 1) * x[i] - (n - i) * x[i]) % MOD;
    }
    ll ysum = 0;
    FOR(i, 1, m + 1) {
        ysum = (ysum + (i - 1) * y[i] - (m - i) * y[i]) % MOD;
    }

    ll ans = (xsum * ysum) % MOD;
    cout << ans << endl;
    return 0;
}