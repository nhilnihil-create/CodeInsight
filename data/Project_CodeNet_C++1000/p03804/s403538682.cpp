#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, m) rep(j, m) cin >> b[i][j];

    int d = n - m + 1;
    rep(i, d) rep(j, d) {
        bool ok = true;
        rep(y, m) rep(x, m) if (a[i + y][j + x] != b[y][x]) ok = false;

        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
