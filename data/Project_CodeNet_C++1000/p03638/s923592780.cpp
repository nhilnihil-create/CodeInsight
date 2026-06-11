#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int h, w, n, t, x, y;

int main() {
    cin >> h >> w >> n;
    int ans[h][w];
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        while (t) {
            ans[x][y] = i;
            --t;
            if (x & 1) {
                if (y == 0) {
                    ++x;
                } else {
                    --y;
                }
            } else {
                if (y == w - 1) {
                    ++x;
                } else {
                    ++y;
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
