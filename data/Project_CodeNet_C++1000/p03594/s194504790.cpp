#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const string col[2] = {"RB", "GY"};

int H, W, d;
char hoge[1005][1005];
char ans[505][505];

void solve1() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i % 2 == 0 && j % 2 == 0) ans[i][j] = 'R';
            else if (i % 2 == 1 && j % 2 == 0) ans[i][j] = 'G';
            else if (i % 2 == 0 && j % 2 == 1) ans[i][j] = 'Y';
            else ans[i][j] = 'R';
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> d;
    int n = H + W - 1;
    for (int i = 0; i < n; i += d) {
        for (int j = 0; j < n; j += d) {
            for (int k = 0; k < d; k++) {
                for (int l = 0; l < d; l++) {
                    if (i + k >= n || j + l >= n) continue;
                    hoge[i + k][j + l] = col[i / d % 2][j / d % 2];
                }
            }
        }
    }

    int geta = W - 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans[i][j] = hoge[i + j][i - j + geta];
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}