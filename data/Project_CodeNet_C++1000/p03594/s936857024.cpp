#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li h, w, d;
    cin >> h >> w >> d;
    if (d % 2 == 1) {
        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                if ((r + c) % 2 == 1) {
                    cout << 'R';
                } else {
                    cout << 'B';
                }
            }
            cout << endl;
        }
    } else {
        string cs = "RGBY";
        const li dd = d / 2;
        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                const li rr = r - ((r + c) % 2 + 2) % 2;
                const li cc = c;
                const li p = (rr + cc + 2000) / 2;
                const li q = (rr - cc + 2000) / 2;

//                cout << r << " " << c << " " << p << " " << q << endl;
                const li ind = (p / dd) % 2 + ((q / dd) % 2) * 2;
                cout << cs[ind];

            }
            cout << endl;
        }
    }

    return 0;
}