#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

template <class T>
struct LazySegmentTree {
    int n;
    T def;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> func;

    LazySegmentTree(int _n, T _def, function<T(T, T)> _func)
        : def(_def), func(_func) {
        n = 1;
        while (n < _n) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1, 0);
        flag.resize(2 * n - 1, false);
    }

    void eval(int k, int l, int r) {
        if (flag[k]) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                flag[k * 2 + 1] = flag[k * 2 + 2] = true;
            }
            lazy[k] = 0;
            flag[k] = false;
        }
    }

    void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += v;
            flag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, v, 2 * k + 1, l, (l + r) / 2);
            update(a, b, v, 2 * k + 2, (l + r) / 2, r);
            node[k] = func(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    T get(int a, int b, int k, int l, int r) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return def;
        if (a <= l && r <= b) return node[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(vl, vr);
    }

    void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }

    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    LazySegmentTree<ll> st(200005, 0, [](ll a, ll b) { return a + b; });
    rep(i, 0, n - 1) {
        ll dif = (a[i + 1] - a[i] + m) % m;
        st.update(a[i] + 2, a[i] + dif + 1, -1);
        st.update(a[i] + dif + 1, a[i] + dif + 2, dif - 1);
    }
    vector<ll> c(m + 1);
    rep(i, 1, m + 1) {
        c[i] += st.get(i, i + 1) + st.get(i + m, i + m + 1);
        c[i] += c[i - 1];
    }
    c[1] += c[m];
    //debug(c);
    ll mn = c[1], cnt = 1;
    rep(i, 2, m + 1) {
        if (mn > c[i]) {
            mn = c[i];
            cnt = i;
        }
    }
    //debug(cnt);
    ll ans = 0;
    rep(i, 0, n - 1) {
        ans += min((a[i + 1] - a[i] + m) % m, (a[i + 1] - cnt + m) % m + 1);
    }
    cout << ans << endl;
    return 0;
}