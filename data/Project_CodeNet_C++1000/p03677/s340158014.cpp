
#include <bits/stdc++.h>

#define null               ""
#define endl               '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const num nsz = 1e5, inf = 9e18;
int n, m;
num ans = inf;

struct segment_tree {
    num tr[4 * nsz + 5], fi[4 * nsz + 5], del[4 * nsz + 5];
    
    void inline up(int u) {
        tr[u] = tr[u << 1] + tr[u << 1 | 1];
    }
    
    void inline down(int u, int l, int r) {
        if (!fi[u] && !del[u])  return;
        int ls = u << 1, rs = u << 1 | 1, mid = (l + r) >> 1;
        num fl = fi[u], fr = fi[u] + (num) (mid - l + 1) * del[u], el = fl + (num) (mid - l) * del[u], er = fr + (num) (r - mid - 1) * del[u];
        tr[ls] += (fl + el) * (mid - l + 1) / 2;
        tr[rs] += (fr + er) * (r - mid) / 2;
        fi[ls] += fi[u];
        fi[rs] += fi[u] + (mid - l + 1) * del[u];
        del[ls] += del[u];
        del[rs] += del[u];
        fi[u] = del[u] = 0;
    }
    
    void upd(int el, int er, int f, int de, int u = 1, int l = 1, int r = m) {
        if (l >= el && r <= er) {
            tr[u] += (num) (f + f + (r - l) * de) * (r - l + 1) / 2;
            fi[u] += f;
            del[u] += de;
            return;
        }
        down(u, l, r);
        int mid = (l + r) >> 1;
        if (el <= mid) {
            upd(el, er, f, de, u << 1, l, mid);
        }
        if (er >= mid + 1) {
            upd(el, er, f + (mid - l + 1) * de, de, u << 1 | 1, mid + 1, r);
        }
        up(u);
    }
    
    num qry(int el, int er, int u = 1, int l = 1, int r = m) {
        if (l >= el && r <= er)  return tr[u];
        down(u, l, r);
        int mid = (l + r) >> 1;
        num res = 0;
        if (el <= mid) {
            res += qry(el, er, u << 1, l, mid);
        }
        if (er >= mid + 1) {
            res += qry(el, er, u << 1 | 1, mid + 1, r);
        }
        return res;
    }
};
segment_tree tr;

int inline read() {
    int res = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); res *= 10, res += c ^ 48, c = getchar());
    return res;
}

int inline calc(int l, int r) {
    return l > r ? r + m - l : r - l;
}

bool inline chk(int pos) {
    return pos >= 1 && pos <= m;
}

int main() {
    n = read();
    m = read();
    int pre = read(), cur;
    cont (i, n - 1) {
        cur = read();
        int mx = calc(pre, cur), pos = cur, l = 1, r = pos - mx + 1, f;
        if (l <= r && chk(l) && chk(r)) {
            tr.upd(l, r, mx, 0);
        }
        l = pos + 1;
        r = min(m, pos + m - mx + 1);
        if (l <= r && chk(l) && chk(r)) {
            tr.upd(l, r, mx, 0);
        }
        l = max(1, pos - mx + 2);
        r = pos;
        f = 1 + (pos - l);
        if (l <= r && chk(l) && chk(r)) {
            tr.upd(l, r, f + (l - 1), -1);
        }
        l = pos + m - mx + 2;
        r = m;
        f = mx - 1;
        if (l <= r && chk(l) && chk(r)) {
            tr.upd(l, r, f + (l - 1), -1);
        }
        pre = cur;
    }
    cont (i, m) {
        ans = min(ans, tr.qry(i, i));
    }
    cout << ans << endl;
}
