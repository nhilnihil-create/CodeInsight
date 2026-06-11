#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // + - + - ...
    ll total = 0, cnt_1 = 0;
    rep(i, n) {
        total += a[i];
        if (i % 2 == 0) {
            if (total <= 0) {
                cnt_1 += (-total) + 1;
                total = 1;
            }
        } else {
            if (total >= 0) {
                cnt_1 += total + 1;
                total = -1;
            }
        }
    }

    // - + - + ...
    total = 0;
    ll cnt_2 = 0;
    rep(i, n) {
        total += a[i];
        if (i % 2 == 1) {
            if (total <= 0) {
                cnt_2 += (-total) + 1;
                total = 1;
            }
        } else {
            if (total >= 0) {
                cnt_2 += total + 1;
                total = -1;
            }
        }
    }

    ll ans = min(cnt_1, cnt_2);
    cout << ans << endl;

    return 0;
}