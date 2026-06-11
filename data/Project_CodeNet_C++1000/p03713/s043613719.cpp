#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll h, w;
    cin >> h >> w;
    ll ans = h * w;
    for (int i = 0; i < 2; i++) {
        for (int a = 1; a < h; a++) {
            ll b = h - a;
            ll c = b / 2;
            ll s1 = a * w;
            ll s2 = (b - c) * w;
            ll s3 = c * w;
            if (s1 >= s2) ans = min(ans, s1 - s3);
            if (s2 > s1 && s1 > s3) ans = min(ans, s2 - s3);
            if (s3 >= s1) ans = min(ans, s2 - s1);
            ll d = w / 2;
            ll s4 = b * (w - d);
            ll s5 = b * d;
            if (s1 >= s4) ans = min(ans, s1 - s5);
            if (s4 > s1 && s1 > s5) ans = min(ans, s4 - s5);
            if (s5 >= s1) ans = min(ans, s4 - s1);
        }
        swap(h, w);
    }
    cout << ans << endl;
    return 0;
}