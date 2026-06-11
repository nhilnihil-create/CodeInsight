#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int H, W, h, w;
int ans_imos[501];

signed main() {
    cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (H % h != 0) {
        for (int i = 0; i <= H / h; i++) {
            ans_imos[i * h] = -i;
        }
        for (int i = 0; i <= H / h; i++) {
            for (int j = 0; j < h - 1 && i * h + j < H; j++) {
                ans_imos[1 + i * h + j] = H / h - i + 1;
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ans_imos[i + 1] - ans_imos[i] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i <= W / w; i++) {
            ans_imos[i * w] = -i;
        }
        for (int i = 0; i <= W / w; i++) {
            for (int j = 0; j < w - 1 && i * w + j < W; j++) {
                ans_imos[1 + i * w + j] = W / w - i + 1;
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ans_imos[j + 1] - ans_imos[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
