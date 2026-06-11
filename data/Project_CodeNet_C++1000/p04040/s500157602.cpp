#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int N = 2e5 + 100;

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

long long add(long long a, long long b) {
    a = a + b;
    if (a > MOD)
        a -= MOD;
    return a;
}

long long fac[N], rfac[N], inv[N];

void calc(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
    fac[0] = rfac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
        rfac[i] = mul(rfac[i - 1], inv[i]);
    }
}

long long comb(int k, int n) {
    return mul(fac[n], mul(rfac[k], rfac[n - k]));
}

void solve() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    calc(2 * max(h, w));

    long long ans = 0;

    for (int i = 1; i <= h - a; i++) {
        int x1 = i, y1 = b, y2 = b + 1, x2 = x1;

        int r1 = x1 - 1 + 1, c1 = y1 - 1 + 1;
        int r2 = h - x2 + 1, c2 = w - y2 + 1;

        ans = add(ans, mul(comb(r1 - 1, r1 + c1 - 2), comb(r2 - 1, r2 + c2 - 2)));
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}
