#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    int x1 = 0, y1 = 0;
    rep(i, 0, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            x1 = max(x1, x);
        } else if (a == 2) {
            w = min(w, x);
        } else if (a == 3) {
            y1 = max(y1, y);
        } else {
            h = min(h, y);
        }
    }
    if (w <= x1 || h <= y1) {
        cout << "0" << endl;
        return 0;
    } else {
        cout << (w - x1) * (h - y1) << endl;
    }
    return 0;
}
