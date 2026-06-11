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

int N, M;
int head[MAX_N], to[MAX_N << 1], nxt[MAX_N << 1], cap;
int dis[MAX_N];
ll cnt[MAX_N];
bool vis[MAX_N];

inline void addE (int u, int v) {
    nxt[++cap] = head[u];
    head[u] = cap;
    to[cap] = v;
}

bool dfs (int x) {
    vis[x] = true;
    bool flag = false;
    for (int i = head[x]; i; i = nxt[i]) {
        if (!vis[to[i]]) {
            dis[to[i]] = dis[x] + 1;
            flag |= dfs(to[i]);
        } else flag |= (!(dis[x] - dis[to[i]] & 1));
    }
    return flag;
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N), read(M);
    int u, v;
    rep (i, 1, M) {
        read(u), read(v);
        addE(u, v);
        addE(v, u);
    }
    rep (i, 1, N) if (!vis[i]) {
        if (!head[i]) { cnt[0]++; continue; }
        if (dfs(i)) cnt[2]++;
        else cnt[1]++;
    }
    ll res = 0;
    res += cnt[2] * cnt[2];
    res += 2LL * cnt[2] * cnt[1];
    res += 2LL * cnt[1] * cnt[1];
    res += 2LL * cnt[0] * (N - cnt[0]);
    res += cnt[0] * cnt[0];
    printf("%lld\n", res);
    return 0;
}
