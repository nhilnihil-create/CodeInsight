#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define rr int
using namespace std;
typedef long long ll;
inline ll read() {
    char i = getchar();
    ll f = 1, res = 0;
    while (i < '0' || i > '9') {
        if (i == '-') f = -1;
        i = getchar();
    }
    while (i >= '0' && i <= '9') {
        res = res * 10 + i - '0';
        i = getchar();
    }
    return f * res;
}
int n /*n个商店*/, m /*d∈[1,m]*/;
const int N = 3e5 + 50;
struct zk {
    int l, r, len;
    bool operator<(const zk &A) const { return len < A.len; }
} a[N];
struct bittree {
    int c[N];
    inline int lowbit(int x) {
        return x & (-x);
    }
    inline void add(int pos, int x) {
        while (pos < N) {
            c[pos] += x;
            pos += lowbit(pos); 
        }
    }
    inline int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    inline int query(int d) {
        int res = 0;
        int now = d;
        while (now <= m) {
            res += sum(now);
            now += d;
        }
        return res;
    }
} C;
int main() {
    n = read(), m = read();
    for (rr i = 1; i <= n; ++i) {
        a[i].l = read();
        a[i].r = read();
        a[i].len = (a[i].r - a[i].l + 1);
    }
    sort(a + 1, a + 1 + n);
    int now = 0;
    for (rr d = 1; d <= m; ++d) {
        while (a[now + 1].len < d && now < n) {
            ++now;
            C.add(a[now].l, 1);
            C.add(a[now].r + 1, -1);
        }
        int ans = (n - now);
        ans += C.query(d);
        printf("%d\n", ans);
    }
}