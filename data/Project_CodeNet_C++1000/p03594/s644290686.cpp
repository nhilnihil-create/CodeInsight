#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, d;
    cin >> h >> w >> d;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int x = i + j;
            int y = i - j + w + (d - w % d);
            cout << "RYGB"[(x % (d * 2) < d) + (y % (d * 2) < d) * 2];
            //cout << x << ',' << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}