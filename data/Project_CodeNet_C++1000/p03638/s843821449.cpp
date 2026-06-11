#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<vector<int>> Graph(H, vector<int>(W));
    int h = 0, w = 0;
    rep(i, N) {
        rep(j, a[i]) {
            Graph[h][w] = i + 1;
            w += pow(-1, h % 2);
            if (w < 0) ++h, w = 0;
            if (w >= W) ++h, w = W - 1;
        }
    }
    rep(i, H) rep(j, W) {
        cout << Graph[i][j];
        if (j == W - 1)
            cout << endl;
        else
            cout << " ";
    }
}