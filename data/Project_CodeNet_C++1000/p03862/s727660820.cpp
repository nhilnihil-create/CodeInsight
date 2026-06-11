#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, x;
    cin >> n >> x;
    vector < int > a(n + 1, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = max(0, a[i] + a[i - 1] - x);
        ans += k;
        a[i] -= k;
    }
    cout << ans << '\n';
}
