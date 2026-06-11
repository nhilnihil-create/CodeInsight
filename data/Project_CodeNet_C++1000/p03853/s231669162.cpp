#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char c[h][w];
    rep(i, h) rep(j, w) cin >> c[i][j];

    rep(i, h) rep(_, 2) {
        rep(j, w) cout << c[i][j];
        cout << endl;
    }

    return 0;
}
