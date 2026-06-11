#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll q, h, s, d; cin >> q >> h >> s >> d;
    ll n; cin >> n;

    ll q1 = q * 4;
    ll h1 = h * 2;

    ll low1 = min({q1, h1, s});
    ll low2 = min(low1 * 2, d);

    if (n >= 2) {
        ll ans = 0;
        if (n % 2 == 0) {
            ans += low2 * (n / 2);
        } else {
            ans += low2 * (n / 2) + low1;
        }

        cout << ans << endl;
    } else {
        cout << low1 << endl;
    }
}