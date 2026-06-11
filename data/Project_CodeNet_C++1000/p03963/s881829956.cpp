#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
};
ll modpow(ll m, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
signed main() {
    int n, x;
    cin >> n >> x;
    ll ans = x * modpow(x - 1, n - 1);
    cout << ans << endl;
}