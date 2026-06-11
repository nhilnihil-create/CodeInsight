#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int w, h, w2, h2;
    if (tx - sx <= 1) {
        w = 1;
    } else {
        w = tx - sx;
    }
    if (ty - sy <= 1) {
        h = 1;
    } else {
        h = ty - sy;
    }
    w2 = w + 2;
    h2 = h + 2;

    rep(i, h) {
        cout << 'U';
    }
    rep(i, w) {
        cout << 'R';
    }
    rep(i, h) {
        cout << 'D';
    }
    rep(i, w) {
        cout << 'L';
    }

    cout << 'L';
    rep(i, h2 - 1) {
        cout << 'U';
    }
    rep(i, w2 - 1) {
        cout << 'R';
    }
    cout << "DR";
    rep(i, h2 - 1) {
        cout << 'D';
    }
    rep(i, w2 - 1) {
        cout << 'L';
    }
    cout << 'U';

    cout << endl;
}