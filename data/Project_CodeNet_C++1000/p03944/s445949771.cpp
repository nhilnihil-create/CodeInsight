#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, w, h, xi, yi, ai;
    cin >> w >> h >> n;
    int ans;
    int xl_max, xr_min, yu_min, yl_max;
    xl_max = yl_max = 0;
    xr_min = yu_min = max(w,h);
    for (int i = 0; i < n ; ++i) {
        cin >> xi >> yi >> ai;
        switch (ai) {
    case 1:
            if (xi > xl_max)
                xl_max = xi;
            break;
    case 2:
            if (xi < xr_min)
                xr_min = xi;
            break;
    case 3:
            if (yi > yl_max)
                yl_max = yi;
            break;
    case 4:
            if (yi < yu_min)
                yu_min = yi;
            break;
        }
    }
    ans = ((xr_min - xl_max> 0) && (yu_min - yl_max > 0)) ? (xr_min - xl_max) * (yu_min - yl_max) : 0;
    cout << ans;

}

int main() {

    solve();
    return 0;
}
