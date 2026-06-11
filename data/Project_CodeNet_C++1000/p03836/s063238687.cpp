#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx - sx;
    int dy = ty - sy;

    // S -> T
    rep(i, dx) cout << 'R';
    rep(i, dy) cout << 'U';

    // T -> S
    rep(i, dx) cout << 'L';
    rep(i, dy) cout << 'D';

    // S -> T
    cout << 'D';
    rep(i, dx + 1) cout << 'R';
    rep(i, dy + 1) cout << 'U';
    cout << 'L';

    // T -> S
    cout << 'U';
    rep(i, dx + 1) cout << 'L';
    rep(i, dy + 1) cout << 'D';
    cout << 'R';

    cout << endl;

    return 0;
}
