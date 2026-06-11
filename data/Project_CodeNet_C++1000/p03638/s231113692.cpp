#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    int n;
    cin >> H >> W >> n;
    vector<int> a(n);
    vector<int> hw(H * W);
    vector<vector<int>> ans(H, vector<int>(W, 0));

    int base = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            hw[base + j] = i + 1;
        }
        base += a[i];
    }

    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (h % 2) {
                ans[h][W - 1 - w] = hw[h * W + w];
            } else {
                ans[h][w] = hw[h * W + w];
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << ans[i][j];
            if (j != W - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
