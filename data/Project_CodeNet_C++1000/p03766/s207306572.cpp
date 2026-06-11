#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 1e9 + 7;
void add(int &x, int y) {
    x += y;
    x %= mod;
}

int mul(int x, int y) {
    return (llong)x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

int fac[1000001];
int rev[1000001];

int nCr(int n, int r) {
    if (r < 0 || n < r) return 0;
    return mul(fac[n], mul(rev[r], rev[n - r]));
}

int nHr(int n, int r) {
    return nCr(n + r - 1, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    rev[n] = pw(fac[n], mod - 2);
    for (int i = n; i > 0; --i) rev[i - 1] = mul(rev[i], i);
    int ans = 1;
    for (int k = 0; k * 3 <= n - 1; ++k)
        add(ans, mul(nHr(k + k + 2, n - 1 - k * 3), n - 1));
    for (int k = 0; k * 3 <= n - 2; ++k)
        add(ans, mul(nHr(k + k + 2, n - 2 - k * 3), mul(n - 1, n - 1)));
    printf("%d\n", ans);
    return 0;
}