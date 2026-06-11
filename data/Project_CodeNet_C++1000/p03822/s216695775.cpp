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
int head[MAX_N], to[MAX_N << 1], nxt[MAX_N << 1], cap;
int val[MAX_N];
int fa[MAX_N];

inline void addE (int u, int v) {
    nxt[++cap] = head[u];
    head[u] = cap;
    to[cap] = v;
}

int tmp[MAX_N], top;
void dfs (int x) {
    val[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) 
        dfs(to[i]);
    top = 0;
    for (int i = head[x]; i; i = nxt[i]) tmp[++top] = val[to[i]];
    std::sort(tmp + 1, tmp + top + 1);
    int s = 1;
    irep (i, top, 1) {
        val[x] = std::max(val[x], tmp[i] + s);
        s++;
    }
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    rep (i, 2, N) {
        read(fa[i]);
        addE(fa[i], i);
    }
    dfs(1);
    printf("%d\n", val[1]);
    return 0;
}