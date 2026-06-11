#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

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

    T get(int a, int b) {
        return get(b) - get(a - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), s(n + 1);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] -= k;
        s[i + 1] = s[i] + a[i];
    }
    vector<ll> e = s;
    sort(e.begin(), e.end());
    e.erase(unique(e.begin(), e.end()), e.end());
    rep(i, 0, n + 1) {
        s[i] = lower_bound(e.begin(), e.end(), s[i]) - e.begin();
    }
    fenwick<ll> st(n + 5);
    ll ans = 0;
    rep(i, 0, n + 1) {
        ans += st.get(s[i]);
        st.add(s[i], 1);
    }
    cout << ans << endl;

    return 0;
}