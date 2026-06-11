#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int x, y, a;

    int x_min = 0;
    int x_max = W;
    int y_min = 0;
    int y_max = H;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> a;
        if (a == 1) {
            x_min = max(x_min, x);
            continue;
        }
        if (a == 2) {
            x_max = min(x_max, x);
            continue;
        }
        if (a == 3) {
            y_min = max(y_min, y);
            continue;
        }
        if (a == 4) {
            y_max = min(y_max, y);
            continue;
        }
    }
    cout << max(0, (x_max - x_min)) * max(0, (y_max - y_min)) << endl;
}