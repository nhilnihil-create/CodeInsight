#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    long h, w, a, b, c, ans = LONG_MAX;
    cin >> h >> w;
    rep(i, h - 1) {
        a = (i + 1) * w;
        b = (h - i - 1) * (w / 2);
        c = ((h - i - 1) * (w - w / 2));
        ans = min(ans, max(a, c) - min(a, b));
        b = (h - i - 1) / 2 * w;
        c = ((h - i - 1) - (h - i - 1) / 2) * w;
        ans = min(ans, max(a, c) - min(a, b));
    }

    rep(i, w - 1) {
        a = h * (i + 1);
        b = (h / 2) * (w - i - 1);
        c = (h - h / 2) * (w - i - 1);
        ans = min(ans, max(a, c) - min(a, b));
        b = h * ((w - i - 1) / 2);
        c = h * ((w - i - 1) - (w - i - 1) / 2);
        ans = min(ans, max(a, c) - min(a, b));
    }
    cout << ans << endl;
}