#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct fenwick {
    vector<T> node;
    int n;
    fenwick(int _n)
        : n(_n) {
        node.resize(n);
    }
    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x) {
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    T get(int a, int b) {  // [a, b]
        return get(b) - (a ? get(a - 1) : 0);
    }
    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), t(n), b, c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = a[i];
        if (i % 2 == 0) {
            b.emplace_back(a[i]);
        } else {
            c.emplace_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = b[i / 2];
        } else {
            a[i] = c[i / 2];
        }
        a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != a[i] % 2) {
            ans++;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}