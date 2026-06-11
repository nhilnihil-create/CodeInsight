#include <bits/stdc++.h>
using namespace std;

int x[510][510];
bool ok = true;

void solve(int h, int w, int H, int W) {
    for (int i = 0; i < H; i++) {
        int cnt = 0; int sum = 0;
        for (int j = 0; j < W; j++) {
            cnt++;
            if (cnt == w) {
                x[i][j] = -(500 * (w-1) + 1);
                cnt = 0;
            } else {
                x[i][j] = 500;
            }
            sum += x[i][j];
        }
        if (sum <= 0) ok = false;
    }
}

void transpose() {
    for (int i = 0; i <= 500; i++) {
        for (int j = i+1; j <= 500; j++) {
            swap(x[i][j], x[j][i]);
        }
    }
}

int main() {
    int H, W; cin >> H >> W;
    int h, w; cin >> h >> w;
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    if (W % w == 0) {
        solve(w, h, W, H);
        transpose();
    } else {
        solve(h, w, H, W);
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j) cout << " ";
            cout << x[i][j];
        }
        cout << endl;
    }
    return 0;
}