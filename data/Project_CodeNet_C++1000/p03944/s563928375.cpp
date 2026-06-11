#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int x[n], y[n], a[n];
    rep(i, n) {
        cin >> x[i] >> y[i] >> a[i];
    }
    bool E[w][h];
    rep(i, w) {
        rep(k, h) {
            E[i][k] = true;
        }
    }

    rep(i, n) {
        if (a[i] == 1) {
            rep(k, x[i]) {
                rep(l, h) {
                    E[k][l] = false;
                }
            }
        } else if (a[i] == 2) {
            for (int k = x[i]; k < w; k++) {
                rep(l, h) {
                    E[k][l] = false;
                }
            }
        } else if (a[i] == 3) {
            rep(k, y[i]) {
                rep(l, w) {
                    E[l][k] = false;
                }
            }
        } else {
            for (int k = y[i]; k < h; k++) {
                rep(l, w) {
                    E[l][k] = false;
                }
            }
        }
    }
    int ans = 0;
    rep(i, w) {
        rep(k, h) {
            if (E[i][k])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
