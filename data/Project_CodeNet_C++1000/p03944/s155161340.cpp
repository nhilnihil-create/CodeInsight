#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int g[105][105];

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            rep(i, h) rep(j, x) g[i][j] = 1;
        } else if (a == 2) {
            rep(i, h) for (int j = w; j >= x; j--) g[i][j] = 1;
        } else if (a == 3) {
            rep(i, y) rep(j, w) g[i][j] = 1;
        } else {
            for (int i = h; i >= y; i--) rep(j, w) g[i][j] = 1;
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) if (g[i][j] == 0) ans++;

    cout << ans << endl;
    return 0;
}
