#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;

    ll ans = 0;

    ll before; cin >> before;
    int increase = 0;

    for (ll i = 1; i < n; ++i) {
        ll a; cin >> a;

        if (before < a) {
            if (increase == 0) {
                increase = 1;
            }

            if (increase == 2) {
                ans++;
                increase = 0;
            }

            before = a;
            continue;
        }

        if (before > a) {
            if (increase == 0) {
                increase = 2;
            }

            if (increase == 1) {
                ans++;
                increase = 0;
            }

            before = a;
            continue;
        }
    }

    ans++;

    cout << ans << endl;
}