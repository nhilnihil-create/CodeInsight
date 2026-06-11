#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector < int64_t > pref(n + 1, 0);
    int64_t ans_odd = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        if (i & 1) {
            if (pref[i] == 0) {
                ++pref[i];
                ++ans_odd;
            }
            else if (pref[i] < 0) {
                ans_odd += 1 - pref[i];
                pref[i] = 1;
            }
        }
        else {
            if (pref[i] == 0) {
                --pref[i];
                ++ans_odd;
            }
            else if (pref[i] > 0) {
                ans_odd += 1 + pref[i];
                pref[i] = -1;
            }
        }
    }
    int64_t ans_even = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        if (i & 1) {
            if (pref[i] == 0) {
                --pref[i];
                ++ans_even;
            }
            else if (pref[i] > 0) {
                ans_even += 1 + pref[i];
                pref[i] = -1;
            }
        }
        else {
            if (pref[i] == 0) {
                ++pref[i];
                ++ans_even;
            }
            else if (pref[i] < 0) {
                ans_even += 1 - pref[i];
                pref[i] = 1;
            }
        }
    }
    cout << min(ans_odd, ans_even) << '\n';
}
