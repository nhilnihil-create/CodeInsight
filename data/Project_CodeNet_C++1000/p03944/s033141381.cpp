#include "bits/stdc++.h"

using namespace std;

void Main() {
    int W, H, N;
    cin >> W >> H >> N;

    int ans = W * H;
    int adjustX = 0;
    int adjustY = 0;
    for (int i = 0; i < N; ++i) {
        int x, y, a;
        cin >> x >> y >> a;
        x += adjustX;
        y += adjustY;
        if (a == 1 && 0 < x) {
            W -= x;
            adjustX -= x;
        }
        else if (a == 2 && x < W) {
            W -= (W - x);
        }
        else if (a == 3 && 0 < y) {
            H -= y;
            adjustY -= y;
        }
        else if (a == 4 && y < H) {
            H -= (H - y);
        }
        if (H <= 0) {
            H = 0;
            break;
        }
        if (W <= 0) {
            W = 0;
            break;
        }
    }
    cout << H * W << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
