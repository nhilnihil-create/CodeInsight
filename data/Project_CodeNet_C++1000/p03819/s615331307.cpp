#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

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
#define MAX_N 300007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;

int N, M, rt[MAX_N];
std::vector<int> L[MAX_N];

struct node { int ls, rs, sum; };

struct chTree {
    int siz;
    node t[MAX_N * 20];
    
    chTree () : siz(0) {}

    void build (int &x, int y, int l, int r, int pos) {
        t[x = ++siz] = t[y];
        t[x].sum++;
        if (l == r) return;
        int mid = l + r >> 1;
        if (pos <= mid) build(t[x].ls, t[y].ls, l, mid, pos);
        else build(t[x].rs, t[y].rs, mid + 1, r, pos);
    }

    int query (int x, int y, int l, int r, int ql, int qr) {
        // printf("%d %d %d %d %d %d\n", l, r, ql, qr, t[x].sum, t[y].sum);
        if (ql <= l && r <= qr) return t[y].sum - t[x].sum;
        int mid = l + r >> 1, ans = 0;
        if (ql <= mid) ans += query(t[x].ls, t[y].ls, l, mid, ql, qr);
        if (mid < qr) ans += query(t[x].rs, t[y].rs, mid + 1, r, ql, qr);
        return ans;
    }
}tr;

inline void init () {
    rep (i, 1, M) {
        rt[i] = rt[i - 1];
        for (int l: L[i])
            tr.build(rt[i], rt[i], 1, M, l);
    }
}

inline int work (int d) {
    int now = d * 2, res = 0;
    for (; now <= M; now += d) {
        res += tr.query(rt[now - d - 1], rt[now - 1], 1, M, 1, now - d);
    }
    now -= d;
    res += tr.query(rt[now - 1], rt[M], 1, M, 1, now);
    return res;
}

inline void solve () {
    rep (i, 1, M) printf("%d\n", work(i));
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N), read(M);
    int l, r;
    rep (i, 1, N) {
        read(l), read(r);
        L[r].push_back(l);
    }
    init();
    solve();
    return 0;
}
