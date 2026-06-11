#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

// 0-indexed bottom up Segment Tree
// UNIT is the identity element of operation func
template <typename T = int>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> dat;
    F func;
    T UNIT;

    SegmentTree(int n_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        // full binary tree: num of leaves = n = 2^k >= n_
        while (n < n_)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
    }
    SegmentTree(vector<T> v_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        while (n < v_.size())
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
        for (int i = 0; i < v_.size(); ++i) {
            dat[n - 1 + i] = v_[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        // leaves are at index n-1 to 2*n-2
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            // k -> parent node
            k = (k - 1) / 2;
            // func(child nodes)
            dat[k] = func(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // get result of func() in [l, r)
    T query(int l, int r) {
        l += n - 1;
        r += n - 1;
        T ret = UNIT;
        while (l < r) {
            if ((l & 1) == 0)
                ret = func(ret, dat[l]);
            if ((r & 1) == 0)
                ret = func(ret, dat[r - 1]);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return ret;
    }
};

int main() {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    auto f = [](ll l, ll r) { return min(l, r); };
    SegmentTree<ll> st(2 * n, f, INF);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.update(i, a[i]);
        st.update(i + n, a[i]);
    }
    ll ret = INF;
    for (int i = 0; i < n; ++i) {
        ll temp = x * i;
        for (int j = n; j < 2 * n; ++j) {
            temp += st.query(j - i, j + 1);
        }
        chmin(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}