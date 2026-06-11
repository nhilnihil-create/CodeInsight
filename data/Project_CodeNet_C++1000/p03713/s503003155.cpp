#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

long calc(long x, long y);

int main() {
    long h, w, ans;
    cin >> h >> w;
    ans = min(calc(h, w), calc(w, h));
    cout << ans << endl;
}

long calc(long x, long y) {
    long a, b, c, ans = LONG_MAX;
    rep(i, x - 1) {
        a = (i + 1) * y;
        b = (x - i - 1) * (y / 2);
        c = ((x - i - 1) * (y - y / 2));
        ans = min(ans, max(a, c) - min(a, b));
        b = (x - i - 1) / 2 * y;
        c = ((x - i - 1) - (x - i - 1) / 2) * y;
        ans = min(ans, max(a, c) - min(a, b));
    }
    return ans;
}