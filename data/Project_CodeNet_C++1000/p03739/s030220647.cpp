#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll n;
vector<ll> a;

ll count(ll sum) {
    ll cnt = 0;
    for (ll i = 1; i < n; ++i) {
        if (sum > 0) {
            sum += a[i];
            if (sum >= 0) {
                cnt += abs(sum) + 1;
                sum = -1;
            }
        } else {
            sum += a[i];
            if (sum <= 0) {
                cnt += abs(sum) + 1;
                sum = 1;
            }
        }
    }

    return cnt;
}

int main() {

    cin >> n;
    ll ans = LINF;

    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (a[0] == 0) {
        ans = min(ans, count(1) + 1);
        ans = min(ans, count(-1) + 1);
    } else {
        ans = min(ans, count(a[0]));

        if (a[0] > 0) {
            ans = min(ans, count(-1) + abs(a[0]) + 1);
        } else {
            ans = min(ans, count(1) + abs(a[0]) + 1);
        }
    }

    cout << ans << endl;
}