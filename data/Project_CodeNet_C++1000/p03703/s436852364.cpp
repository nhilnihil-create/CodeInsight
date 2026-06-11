#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int const maxn = 2e5 + 10;

// 等价于 p * 2
inline int lc(int p) {return p << 1;}
// 等价于 p * 2 + 1
inline int rc(int p) {return p << 1 | 1;}
int n;
struct segt {
    struct Tree {
        int l, r;
        ll sum;
        void update(ll v) {
            sum += v * (r - l + 1);
        }
    } tree[maxn << 2];

    void pushup(int p) {
        tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
    }

    void build(int p, int l, int r) {
        tree[p].l = l, tree[p].r = r;
        tree[p].sum = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lc(p), l, mid);
        build(rc(p), mid + 1, r);
        pushup(p);
    }

    void update(int p, int x, ll v) {
        int L = tree[p].l, R = tree[p].r;
        if (L == x && L == R) {
            tree[p].update(v);
            return;
        }
        int mid = (L + R) >> 1;
        if (x <= mid) update(lc(p), x, v);
        else  update(rc(p), x, v);
        pushup(p);
    }
    ll query(int p, int l, int r) {
        int L = tree[p].l, R = tree[p].r;
        // if (L <= 0 || R > n || L == 0 || R == 0) return 0;
        // if (L > r || R < l) return 0;
        int mid = (L + R) >> 1;
        if (l <= L && r >= R) {
            return tree[p].sum;
        }
        ll res = 0;
        if (l <= mid) res += query(lc(p), l, r);
        if (r > mid) res += query(rc(p), l, r);
        return res;
    }
}seg;

struct node {
    int pos;
    ll val;
    bool operator<(const node &__) const {
        if (val == __.val) return pos < __.pos;
        return val < __.val;
    }
} pre[maxn];

int main(void) {
    ll k;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        pre[i].val = pre[i - 1].val + x - k;
        pre[i].pos = i;
    }
    seg.build(1, 1, n);
    sort(pre + 1, pre + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i].val >= 0) ans++;
        ans += seg.query(1, 1, pre[i].pos - 1);
        seg.update(1, pre[i].pos, 1);
    }
    printf("%lld\n", ans);

    return 0;
}