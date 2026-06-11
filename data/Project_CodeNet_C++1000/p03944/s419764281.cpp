#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int W, H, N;
    cin >> W >> H >> N;

    int o_x = 0, o_y = 0;

    while (N--) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            if (o_x <= x)
                o_x = x;
        } else if (a == 2) {
            if (W >= x)
                W = x;
        } else if (a == 3) {
            if (o_y <= y)
                o_y = y;
        } else if (a == 4) {
            if (H >= y)
                H = y;
        }
    }
    if (o_x <= W && o_y <= H)
        cout << (W - o_x) * (H - o_y) << endl;
    else
        cout << 0 << endl;
}
