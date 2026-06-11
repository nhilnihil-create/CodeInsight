#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    int x, y, a;
    int l = 0, r = w, d = 0, u = h;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> a;
        if (a == 1) l = max(l, x);
        if (a == 2) r = min(r, x);
        if (a == 3) d = max(d, y);
        if (a == 4) u = min(u, y);
    }
    cout << max(u - d, 0) * max(r - l, 0) << endl;
    return 0;
}