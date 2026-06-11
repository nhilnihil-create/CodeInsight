#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    ll mn = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a == mn + 1) {
            mn++;
            continue;
        }
        ans += (a - 1) / (mn + 1);
        if (mn == 0) {
            mn++;
        }
        debug(mn, ans);
    }
    cout << ans << '\n';
    return 0;
}