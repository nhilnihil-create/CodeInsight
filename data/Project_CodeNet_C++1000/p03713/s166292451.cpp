#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll h, w, z = (ll)100000000000;
    cin >> h >> w;
    if (h % 3 == 0) z = min(z, 0ll);
    else z = min(z, w);
    if (w % 3 == 0) z = min(z, 0ll);
    else z = min(z, h);
    for (int i = 1; i < h; i++) {
        ll a = i * w, b, c;
        if (w % 2 == 0) b = c = (w / 2) * (h - i);
        else b = (w / 2) * (h - i), c = (w / 2 + 1) * (h - i);
        z = min(z, max({a, b, c}) - min({a, b, c}));
    }
    for (int i = 1; i < w; i++) {
        ll a = i * h, b, c;
        if (h % 2 == 0) b = c = (h / 2) * (w - i);
        else b = (h / 2) * (w - i), c = (h / 2 + 1) * (w - i);
        z = min(z, max({a, b, c}) - min({a, b, c}));
    }
    cout << z;
}
