#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

void putChars(int n, char c) { rep(i, n) cout << c; }

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int h = ty - sy;
    int w = tx - sx;

    // 1往復目
    putChars(w, 'R');
    putChars(h, 'U');
    putChars(w, 'L');
    putChars(h, 'D');

    // 2往復目
    putChars(1, 'D');
    putChars(w + 1, 'R');
    putChars(h + 1, 'U');
    putChars(1, 'L');
    putChars(1, 'U');
    putChars(w + 1, 'L');
    putChars(h + 1, 'D');
    putChars(1, 'R');
    cout << endl;

    return 0;
}
