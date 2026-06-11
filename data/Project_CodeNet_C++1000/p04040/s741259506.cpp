// Crt. 2019-12-08  11:38:25
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 400005
using namespace std;
const int Mod = 1e9 + 7;

inline int fsp(int x, int p = Mod - 2) {
    int res = 1;
    while (p) {
        if (p & 1) res = 1ll * res * x % Mod;
        x = 1ll * x * x % Mod, p >>= 1;
    } return res;
}

inline void inc(int &x, int y) {
    x += y, x -= x >= Mod ? Mod : 0;
}

int n, m, a, b, fac[N], ifac[N];

inline int C(int x, int y) {
    return 1ll * fac[x + y] * ifac[x] % Mod * ifac[y] % Mod;
}

inline int walk(int x, int y, int xx, int yy) {
    return C(xx - x, yy - y);
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    n = 2e5;

    for (int i = fac[0] = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % Mod;
    ifac[n] = fsp(fac[n]);
    for (int i = n; i >= 1; --i)
        ifac[i - 1] = 1ll * ifac[i] * i % Mod;

    cin >> n >> m >> a >> b;

    int ans = 0;
    for (int i = 1; i <= n - a; ++i) {
        inc(ans, 1ll * walk(1, 1, i, b) * walk(i, b + 1, n, m) % Mod);
    }

    cout << ans << endl;

    return 0;
}
