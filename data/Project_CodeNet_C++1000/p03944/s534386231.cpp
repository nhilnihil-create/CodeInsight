#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int grid[h][w];
    fill(grid[0], grid[h], 0);
    int x[n], y[n], a[n];
    rep(i, n) {
        cin >> x[i] >> y[i] >> a[i];
        if (a[i] == 1) {
            rep(j, h) {
                rep(k, w) {
                    if (k < x[i]) grid[j][k] = 1;
                }
            }
        } else if (a[i] == 2) {
            rep(j, h) {
                rep(k, w) {
                    if (k >= x[i]) grid[j][k] = 1;
                }
            }
        } else if (a[i] == 3) {
            rep(j, h) {
                rep(k, w) {
                    if (j < y[i]) grid[j][k] = 1;
                }
            }
        } else if (a[i] == 4) {
            rep(j, h) {
                rep(k, w) {
                    if (j >= y[i]) grid[j][k] = 1;
                }
            }
        }
    }
    int cnt = 0;
    rep(i, h) {
        rep(j, w) {
            if (grid[i][j] == 0) cnt++;
        }
    }
    cout << cnt << endl;
}