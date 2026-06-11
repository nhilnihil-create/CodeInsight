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
#define MAX_N 300007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;

int N;
int p[MAX_N];
int s[MAX_N], a[MAX_N], b[MAX_N];

inline void solve () {
    int M = N * N;
    rep (i, 1, M) {
        if (a[i]) {
            s[a[i]]++;
            if (s[a[i]] != a[i]) { puts("No"); exit(0); }
        } else {
            bool flag = false;
            rep (j, 1, N) if (s[b[j]] < b[j] - 1) {
                s[a[i] = b[j]]++;
                flag = true;
                break;
            }
            if (!flag) {
                rep (j, 1, N) if (s[j] >= j && s[j] < N) {
                    s[a[i] = j]++;
                    flag = true;
                    break;
                }
            }
            if (!flag) { puts("No"); exit(0); }
        }
    }
    puts("Yes");
    rep (i, 1, M) printf("%d ", a[i]); puts("");
}

bool cmp (int x, int y) { return p[x] < p[y]; }

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    rep (i, 1, N) a[p[i] = input<int>()] = i, b[i] = i;
    std::sort(b + 1, b + N + 1, cmp);
    solve();
    return 0;
}