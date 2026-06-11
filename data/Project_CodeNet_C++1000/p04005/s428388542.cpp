#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    vector<ll> l(3);
    for (int i = 0; i < 3; ++i) {
        cin >> l[i];
    }

    ll ans = LINF;

    for (int i = 0; i < 3; ++i) {
        ll d1 = l[i] / 2;
        ll d2 = l[i] - d1;

        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;

            d1 *= l[j];
            d2 *= l[j];
        }

        ans = min(ans, abs(d1 - d2));
    }

    cout << ans << endl;
}