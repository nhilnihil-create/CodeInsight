#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector < int > nxt(n + 1, 0);
    for (int i = 1; i <= n; ++i) 
        nxt[i] = int(prev(upper_bound(a.begin(), a.end(), 2 * a[i])) - a.begin());
    vector < int > head(n + 1, 0);
    for (int i = n; i; --i) {
        head[i] = nxt[i];
        if (nxt[i] != i)
            head[i] = head[nxt[i]];
    }
    vector < int64_t > pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i];
    int good = n;
    for (int i = 0; i <= n; ++i) {
        if (head[i] == n) {
            good = a[i];
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += (2 * pref[head[i]] >= int64_t(good));
    cout << ans << '\n';
}
