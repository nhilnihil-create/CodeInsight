#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 510;

int H, W, h, w;
int ans[MAX];

int main() {
    cin >> H >> W >> h >> w;
    if (H%h == 0 && W%w == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    bool t = (H%h == 0);
    if (t) swap(H, W), swap(h, w);

    ans[0] = H/h+1;
    for (int i = 1; i < h-1; i++) ans[i] = 0;
    ans[h-1] = -ans[0]-1;

    if (t) {
        for (int j = 0; j < W; j++)
            for (int i = 0; i < H; i++)
                cout << ans[i%h] << ((i == H-1) ? "\n":" ");
    } else {
        for (int j = 0; j < H; j++)
            for (int i = 0; i < W; i++)
                cout << ans[j%h] << ((i == W-1) ? "\n":" ");
    }
}