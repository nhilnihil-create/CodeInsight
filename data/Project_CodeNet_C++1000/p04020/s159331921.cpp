#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > a(n + 1, 0);
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i - 1] && a[i]) {
            ++ans;
            --a[i];
        }
        ans += a[i] / 2;
        a[i] %= 2;
    }
    cout << ans << '\n';
}
