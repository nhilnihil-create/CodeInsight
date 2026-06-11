#include <bits/stdc++.h>

using namespace std;

namespace {
    int H, W, d;
    void input() {
        cin >> H >> W >> d;
    }

    void solve() {
        auto T = 2000;
        auto F = vector<string>(H, string(W, '0'));
        auto s = "RGBY";
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                auto j = x + y + T;
                auto i = x - y + T;
                F[y][x] = s[ (i / d) % 2 * 2 + (j / d) % 2 ];
            }
        }
        for (auto L : F) cout << L << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}

