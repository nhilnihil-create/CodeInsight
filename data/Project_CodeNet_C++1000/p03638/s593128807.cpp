#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int a[n], g[h][w];
    rep(i, n) cin >> a[i];

    int cnt = 0, color = 1;
    rep(i, h) {
        if (i % 2 == 0) {
            rep(j, w) {
                if (cnt >= a[color - 1]) color++, cnt = 0;
                g[i][j] = color, cnt++;
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                if (cnt >= a[color - 1]) color++, cnt = 0;
                g[i][j] = color, cnt++;
            }
        }
    }

    rep(i, h) rep(j, w) {
        cout << g[i][j];
        if (j == w - 1)
            cout << endl;
        else
            cout << ' ';
    }
    return 0;
}
