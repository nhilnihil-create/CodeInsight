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
            ll M = max(max(s1, s2), s3);
            ll m = min(min(s1, s2), s3);
            ans = min(ans, M - m);
            ll d = w / 2;
            ll s4 = b * (w - d);
            ll s5 = b * d;
            M = max(max(s1, s4), s5);
            m = min(min(s1, s4), s5);
            ans = min(ans, M - m);
        }
        swap(h, w);
    }
    cout << ans << endl;
    return 0;
}