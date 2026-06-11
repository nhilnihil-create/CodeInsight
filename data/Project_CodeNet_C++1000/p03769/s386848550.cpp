#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

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
#define MAX_N 3007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define lep(i, l, r) for(int i = l; i < r; ++i)
#define irep(i, r, l) for(int i = r; i >= l; --i)
#define ilep(i, r, l) for(int i = r; i > l; --i)
typedef long long ll;
typedef std::deque<int> deq;

ll N;

struct node {
    deq a, b;
};

node dfs (ll x, int p) {
    node ans;
    if (x == 0) return ans;
    if (x & 1LL) {
        ans = dfs((x - 1LL) >> 1, p + 1);
        ans.a.push_front(p);
        ans.b.push_front(p);
        return ans;
    } else {
        ans = dfs(x - 1LL, p + 1);
        ans.a.push_front(p);
        ans.b.push_back(p);
        return ans;
    }
}

int main () {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    node res = dfs(N, 1);
    printf("%d\n", res.a.size() + res.b.size());
    while (!res.a.empty()) {
        printf("%d ", res.a.front());
        res.a.pop_front();
    }
    while (!res.b.empty()) {
        printf("%d ", res.b.front());
        res.b.pop_front();
    } puts("");
    return 0;
}
