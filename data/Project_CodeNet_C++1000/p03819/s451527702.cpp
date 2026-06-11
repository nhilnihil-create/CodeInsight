#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 3e5 + 10;
const int MAXM = 3e5 + 10;

template <typename value_t>
class fenwick {
   public:
    fenwick(int n) {
        memset(c, 0, sizeof c);
        this->n = n;
    }

    void add(int i, value_t x) {
        while (i <= n) {
            c[i] += x;
            i += Lowbit(i);
        }
    }

    value_t sum(int x) {
        value_t sum = 0;
        while (x > 0) {
            sum += c[x];
            x -= Lowbit(x);
        }
        return sum;
    }

    value_t sum(int x1, int x2) { return sum(x2) - sum(x1 - 1); }

   private:
    value_t c[MAXN];
    int n;

    inline int Lowbit(int x) { return x & (-x); }
};

struct interval {
    int l, r;
} a[MAXM];
struct comp {
    bool operator()(const interval& a, const interval& b) {
        return a.r - a.l < b.r - b.l;
    }
};

#include <cctype>
#include <cstdio>

inline int read() {
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        X = (X << 3) + (X << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -X : X;
}

int main() {
    int n = read();
    int m = read();
    for (int i = 1; i <= n; i++) {
        a[i].l = read();
        a[i].r = read();
    }  
    sort(a + 1, a + n + 1, comp());
    fenwick<int>* tree = new fenwick<int>(m);
    int cur = 1;
    for (int d = 1; d <= m; d++) {
        while (cur <= n && a[cur].r - a[cur].l + 1 < d) {
            tree->add(a[cur].l, 1);
            tree->add(a[cur].r + 1, -1);
            cur++;
        }
        int ans = n - cur + 1;
        for (int i = d; i <= m; i += d) {
            ans += tree->sum(i);
        }
        cout << ans << endl;
    }
}