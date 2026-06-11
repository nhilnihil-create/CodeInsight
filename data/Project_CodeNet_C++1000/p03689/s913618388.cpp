#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 510;

int a[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int k = 501;
    ll s = ll(H) * W * k;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            a[i][j] = k;
        }
    }
    for (int i = h - 1; i < H; i += h) {
        for (int j = w - 1; j < W; j += w) {
            a[i][j] = -(h * w - 1) * k - 1;
            s += a[i][j] - k;
        }
    }
    if (s > 0) {
        cout << "Yes";
        for (int i = 0; i < H; ++i) {
            cout << '\n';
            for (int j = 0; j < W; ++j) {
                cout << a[i][j] << ' ';
            }
        }
    } else {
        cout << "No";
    }
    return 0;
}