#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long h, w;
    cin >> h >> w;

    long long ans = 1LL<<60;
    for (long long i = 1; i <= h - 1; i++) {
        long long sa = w * i;
        long long sb = w % 2 == 0 ? (h - i) * (w / 2) : (h - i) * (w / 2 + 1);
        long long sc = (h - i) * (w / 2);
        long long s_mx = max({sa, sb, sc});
        long long s_mn = min({sa, sb, sc});
        ans = min(ans, s_mx - s_mn);

        sb = (h - i) % 2 == 0 ? ((h - i) / 2) * w : ((h - i) / 2 + 1) * w;
        sc = ((h - i) / 2) * w;
        s_mx = max({sa, sb, sc});
        s_mn = min({sa, sb, sc});
        ans = min(ans, s_mx - s_mn);
    }

    for (long long i = 1; i <= w - 1; i++) {
        long long sa = h * i;
        long long sb = h % 2 == 0 ? (w - i) * (h / 2) : (w - i) * (h / 2 + 1);
        long long sc = (w - i) * (h / 2);
        long long s_mx = max({sa, sb, sc});
        long long s_mn = min({sa, sb, sc});
        ans = min(ans, s_mx - s_mn);

        sb = (w - i) % 2 == 0 ? ((w - i) / 2) * h : ((w - i) / 2 + 1) * h;
        sc = ((w - i) / 2) * h;
        s_mx = max({sa, sb, sc});
        s_mn = min({sa, sb, sc});
        ans = min(ans, s_mx - s_mn);
    }

    cout << ans << endl;
    return 0;
}