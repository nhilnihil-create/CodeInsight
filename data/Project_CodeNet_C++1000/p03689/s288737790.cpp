#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 1000

signed main() {
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    ll a[H][W];
    fill(a[0], a[H], MAX);
    rep(i, H) {
        rep(j, W) {
            if ((i - (h - 1)) % h == 0 && (j - (w - 1)) % w == 0)
                a[i][j] = - MAX * (h * w - 1) - 1;
        }
    }
    ll sum = 0;
    rep(i, H) {
        rep(j, W) {
            sum += a[i][j];
        }
    }
    if(sum <= 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i, H) {
        rep(j, W) {
            if(j) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}