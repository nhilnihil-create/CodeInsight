#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

namespace IO {
    template <typename _T>
    inline bool read (_T& x) {
        x = 0;
        _T y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return false;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return true;
    }

    template <typename _T>
    inline _T input () {
        _T x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        x *= y;
        return x;
    }
};
using namespace IO;

namespace modular {
    const int MOD = 1000000007;

    inline int add (int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }

    inline void inc (int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }

    inline int mul (int x, int y) { return 1LL * x * y % MOD; }

    inline int qpow (int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ans = mul(ans, x);
        return ans;
    }
};

#define reg register
#define MAX_N 200007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;

int N;
ll s[MAX_N], c[MAX_N];
int head[MAX_N], to[MAX_N << 1], nxt[MAX_N << 1], cap;
int deg[MAX_N];

inline void addE (int u, int v) {
    nxt[++cap] = head[u];
    head[u] = cap;
    to[cap] = v;
}

bool dfs (int x, int las) {
    int cnt = 0;
    ll tmp = 0;
    for (int i = head[x]; i; i = nxt[i]) if (to[i] != las) {
        cnt++;
        if (!dfs(to[i], x)) return false;
        tmp += c[to[i]];
    }
    if (!cnt) return c[x] = s[x], true;
    if (tmp > 2LL * s[x] || s[x] > tmp) return false;
    if (cnt == 1) return c[x] = tmp, s[x] == tmp;
    // printf("%d %d %d %d\n", x, cnt, tmp, s[x]);
    ll mx = 0;
    for (int i = head[x]; i; i = nxt[i]) if (to[i] != las) {
        mx = std::max(mx, c[to[i]]);
    }
    ll a = mx * 2 > tmp ? tmp - mx : tmp / 2LL;
    if (a < tmp - s[x]) return false;
    return c[x] = 2LL * s[x] - tmp, true;
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    rep (i, 1, N) read(s[i]);
    if (N == 1) return puts(s[1] == 0 ? "YES" : "NO"), 0;
    if (N == 2) return puts(s[1] == 1 && s[2] == 1 ? "YES" : "NO"), 0;
    int u, v;
    rep (i, 2, N) {
        read(u), read(v);
        addE(u, v);
        addE(v, u);
        deg[u]++, deg[v]++;
    }
    int rt = 0;
    rep (i, 1, N) if (deg[i] > 1) rt = i;
    puts(dfs(rt, 0) && c[rt] == 0 ? "YES" : "NO");
    return 0;
}