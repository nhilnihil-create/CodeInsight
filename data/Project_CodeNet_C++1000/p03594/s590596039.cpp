#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int h, w, d;
    cin >> h >> w >> d;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            cout << "RYGB"[((i + j) / d % 2) | (((w + i - j) / d % 2) << 1)];
        cout << '\n';
    }

    return 0;
}
