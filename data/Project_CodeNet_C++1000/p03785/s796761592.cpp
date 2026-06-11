#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, c, k; cin >> n >> c >> k;
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll limit = t[i] + k;
        ll cnt = 1;
        ++i;

        while (t[i] <= limit && cnt + 1 <= c) {
            ++cnt;
            ++i;
        }

        --i;
        ++ans;
    }

    cout << ans << endl;
}