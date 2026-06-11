#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

lli diff(lli hA, lli wA, lli hB, lli wB, lli hC, lli wC) {
    lli areas[]{hA * wA, hB * wB, hC * wC};

    lli mx = *max_element(areas, areas + 3);
    lli mn = *min_element(areas, areas + 3);
    return mx - mn;
}

int main() {

//    freopen("input.txt", "r", stdin);

    int H, W;
    cin >> H >> W;

    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0;
    } else {
        int A, B, C;
        lli ans = 10e+5;
        int hA, wA, hB, wB, hC, wC;

        wA = W;
        for (hA = 1; hA <= (H / 2) + 1; hA++) {

            // Try case 1
            hB = hC = H - hA;
            wB = (W + 1) / 2;
            wC = W / 2;
            ans = min(ans, diff(hA, wA, hB, wB, hC, wC));

            // Try case 2
            hB = (H - hA) / 2;
            hC = (H - hA + 1) / 2;
            wB = wC = W;
            ans = min(ans, diff(hA, wA, hB, wB, hC, wC));
        }

        hA = H;
        for (wA = 1; wA <= (W / 2) + 1; wA++) {
            // Try case 3
            hB = hC = H;
            wB = (W - wA) / 2;
            wC = (W - wA + 1) / 2;
            ans = min(ans, diff(hA, wA, hB, wB, hC, wC));

            // Try case 4
            wB = wC = W - wA;
            hB = H / 2;
            hC = (H + 1) / 2;
            ans = min(ans, diff(hA, wA, hB, wB, hC, wC));
        }
        cout << ans;
    }
    cout << "\n";
    return 0;
}