#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int W, H, N;
    cin >> W >> H >> N;

    int xmin = 0, xmax = W;
    int ymin = 0, ymax = H;
    while (N--) {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a) {
            case 1:
                xmin = max(xmin, x);
                break;
            case 2:
                xmax = min(xmax, x);
                break;
            case 3:
                ymin = max(ymin, y);
                break;
            case 4:
                ymax = min(ymax, y);
                break;
        }
    }

    cout << ((xmax <= xmin || ymax <= ymin) ? 0 : (xmax - xmin) * (ymax - ymin)) << endl;

    return 0;
}