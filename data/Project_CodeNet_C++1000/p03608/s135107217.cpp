#include <bits/stdc++.h>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int main() {
    int n, m, R;
    scanf("%d%d%d", &n, &m, &R);
    int r[R];
    rep(i, R) scanf("%d", &r[i]), --r[i];
    int dist[n][n];
    rep(i, n) {
        rep(j, n) dist[i][j] = mod;
        dist[i][i] = 0;
    }
    rep(i, m) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        dist[a][b] = dist[b][a] = c;
    }
    rep(k, n) rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = mod;
    int p[R];
    iota(p, p + R, 0);
    do {
        int tmp = 0;
        rep(i, R - 1) tmp += dist[r[p[i]]][r[p[i + 1]]];
        chmin(ans, tmp);
    } while (next_permutation(p, p + R));
    printf("%d\n", ans);
}