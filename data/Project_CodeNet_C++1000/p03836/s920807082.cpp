#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    rep(i, tx - sx) cout << "R";
    rep(i, ty - sy) cout << "U";

    rep(i, tx - sx) cout << "L";
    rep(i, ty - sy) cout << "D";

    cout << "D";
    rep(i, tx - sx + 1) cout << "R";
    rep(i, ty - sy + 1) cout << "U";

    cout << "LU";
    rep(i, tx - sx + 1) cout << "L";
    rep(i, ty - sy + 1) cout << "D";

    cout << "R" << endl;

    return 0;
}