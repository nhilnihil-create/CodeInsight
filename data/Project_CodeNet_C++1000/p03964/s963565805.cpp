#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int64_t > t(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> a[i];
    int64_t cur_t = t[0], cur_a = a[0];
    for (int i = 1; i < n; ++i) {
        int64_t l = 1, r = 1000000000000000020 / (t[i] + a[i]);
        while (r - l > 1) {
            int64_t m = (l + r) / 2;
            if (m * t[i] >= cur_t && m * a[i] >= cur_a)
                r = m;
            else
                l = m;
        }
        if (l * t[i] >= cur_t && l * a[i] >= cur_a)
            cur_t = l * t[i], cur_a = l * a[i];
        else
            cur_t = r * t[i], cur_a = r * a[i];
    }
    cout << cur_t + cur_a << '\n';
}
