#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int H, W, D;

char a[505][505];

void print_polygon(int sx, int sy, char c) {
    for (int dy = -D/2+1; dy < D/2; ++dy) {
        for (int dx = abs(dy); dx <= D-1-abs(dy); ++dx) {
            int x = sx + dx, y = sy + dy;
            if (0 <= x && x < H && 0 <= y && y < W) {
                a[x][y] = c;
            }
        }
    }
}

int main() {
    cin >> H >> W >> D;
    for (int j= 0; j < 505; ++j) fill(a[j], a[j]+505, '.');
    if (D % 2 == 1) {
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                cout << (((j+k)%2==0)?'R':'G');
            }
            cout << endl;
        }
        return 0;
    }

    for (int x = -2*D; x <= H+2*D; x += D*2) {
        for (int y = -2*D; y <= W+2*D; y += D*2) {
            print_polygon(x, y, 'R');
            print_polygon(x+D/2, y+D/2, 'Y');
            print_polygon(x+D/2, y-D/2, 'B');
            print_polygon(x+D, y, 'G');

            print_polygon(x+D, y-D, 'R');
            print_polygon(x+3*D/2, y-D/2, 'Y');
            print_polygon(x+3*D/2, y-3*D/2, 'B');
            print_polygon(x+2*D, y-D, 'G');
        }
    }

    for (int j = 0; j < H; ++j) {
        for (int k = 0; k < W; ++k) {
            cout << a[j][k];
        }
        cout << endl;
    }

    return 0;
}
