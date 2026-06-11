#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define reg register
#define MAX_N 200007
#define rep(i, l, r) for(int i = l; i <= r; ++i)
typedef long long ll;

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

int M, N;
int a[MAX_N], b[MAX_N], c[MAX_N];

inline int calc (int x) {
    rep (i, 1, N) b[i] = (x < a[i]);
    // printf("%d:\n", x);
    // rep (i, 1, N) printf("%d ", b[i]); puts("");
    for (int i = 1, j = 1; i <= N; i = j) {
        int l, r;
        while (j < N && b[j + 1] == b[j]) j++;
        l = j;
        while (j < N && b[j + 1] != b[j]) j++;
        r = j;
        // printf("%d %d\n", l, r);
        if (b[l] == b[r]) {
            rep (k, l + 1, r - 1) b[k] = b[l];
        } else {
            int sum = 0;
            rep (k, l, r) sum += (b[k] == b[l]);
            rep (k, l, l + sum - 1) b[k] = b[l];
            rep (k, l + sum, r) b[k] = b[r];
        }
        j++;
    }
    // rep (i, 1, N) printf("%d ", b[i]); puts("");
    return b[M];
}

int main () {
    //freopen ("triangle.in", "r", stdin);
    //freopen ("triangle.out", "w", stdout);
    read(M), N = 2 * M - 1;
    rep (i, 1, N) read(a[i]), c[i] = a[i];
    std::sort(c + 1, c + N + 1);
    int l = 1, r = N, mid, ans = 0;
    while (l <= r) {
        mid = l + r >> 1;
        if (!calc(c[mid])) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", c[ans]);
    return 0;
}
