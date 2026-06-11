#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;
    ll taka;
    ll ao;

    cin >> taka >> ao;

    for (ll i = 2; i <= n; ++i) {
        ll t, a; cin >> t >> a;

        ll bt = (taka + (t - 1)) / t;
        ll ba = (ao + (a - 1)) / a;

        ll mx = max(bt, ba);

        taka = t * mx;
        ao = a * mx;
    }

    cout << taka + ao << endl;
}