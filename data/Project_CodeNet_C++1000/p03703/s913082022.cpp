#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    const T e;
    const F f;
    size_t sz;
    vector<T> tree;

    SegmentTree(size_t n, const F &f, const T &e = 0) : f(f), e(e) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(2*sz, e);
    }

    void set(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
        copy(begin, end, tree.begin() + sz);
        for(size_t k=sz-1; k>0; k--)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    void update(size_t k, const T &x) {
        k += sz;
        tree[k] = x;
        while(k >>= 1)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    T query(size_t a, size_t b) const {
        T l = e, r = e;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) l = f(l, tree[a++]);
            if(b & 1) r = f(tree[--b], r);
        }
        return f(l, r);
    }

    T operator[](const size_t k) const {
        return tree[sz + k];
    }
};

int main(void) {
    long n, k;
    cin >> n >> k;

    vector<long> a(n);
    for(auto &e: a) cin >> e, e -= k;

    vector<long> b(n+1);
    for(long i=1; i<=n; i++)
        b[i] = b[i-1] + a[i-1];

    vector<pair<long,long>> c(n+1);
    for(long i=0; i<=n; i++)
        c[i] = make_pair(b[i], i);
    sort(c.begin(), c.end());

    SegmentTree<long> st(n+1, [&](long a, long b){return a+b;}, 0);

    long r = 0;
    for(long i=0; i<=n; i++) {
        long cc = c[i].second;
        r += st.query(0, cc);
        st.update(cc, 1);
    }
    cout << r << endl;

}
