#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;
    ll a[n];
    rep(i, n) cin >> a[i];

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ll sum = a[i - 1] + a[i];
        if (sum > x) {
            if (a[i - 1] > x) {
                ans += sum - x;
                a[i] = 0;
            } else {
                a[i] -= sum - x;
                ans += sum - x;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
