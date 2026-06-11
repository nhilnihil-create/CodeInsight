#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
ll n, p, a[100], f[100][2];

int main() {
    cin >> n >> p;
    rep(i, 1, n) cin >> a[i], a[i] %= 2;
    f[0][0] = 1;
    rep(i, 1, n) {
        rep(j, 0, 1) {
            f[i][j] += f[i - 1][j ^ a[i]] + f[i - 1][j];
        }
    }
    printf("%lld\n", f[n][p]);
    return 0;
}
