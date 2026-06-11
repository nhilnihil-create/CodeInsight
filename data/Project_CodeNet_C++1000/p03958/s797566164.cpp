#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int k, t;
    cin >> k >> t;
    int a[t];
    rep(i, t) cin >> a[i];

    if (t == 1) {
        cout << a[0] - 1 << endl;
        return 0;
    }

    sort(a, a + t);
    int l = 0, r = t - 1;
    int i = 0, cnt = 0;
    while (!all_of(a, a + t, [](int x) { return x == 0; })) {
        if (i % 2 == 0) {
            if (a[l] == 0) l++;
            a[l]--;
        } else {
            if (a[r] == 0) r++;
            a[r]--;
        }

        if (l == r) cnt++;
        i++;
    }

    if (cnt > 0) cnt--;
    cout << cnt << endl;
    return 0;
}
