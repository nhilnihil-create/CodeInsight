#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li h, w, d;
    cin >> h >> w >> d;

    if (d % 2 == 1) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << (((i + j) & 1) ? 'R' : 'B');
            }
            cout << endl;
        }
    } else {
        const int size = d / 2;
        vector<vector<char>> b(h, vector<char>(w));
        string colors = "RGBY";
        for (int k = -h; k <= w; ++k) {
            int cycle = (k + h) / 2;

            int init_color = cycle / size % 4;
            int offset = cycle % size;
            for (int v = 0; v < h; ++v) {
                int i = v;
                int j = k + v;

                int color_shifts = (offset + v) / size;
                int color = (init_color + color_shifts * 2) % 4;
                if (0 <= i && i < h && 0 <= j && j < w) {
                    b[i][j] = colors[color];
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << b[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}