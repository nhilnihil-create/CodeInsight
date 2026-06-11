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

// Binary Indexed Tree / Fenwick tree
// can calculate partial sum in O(logN)
// can update single datum in O(logN)
// lower_bound is binary search O(logN)
// 0-indexed!!!
template <typename T = int>
struct BinaryIndexedTree {
    int n;
    vector<T> bit;
    BinaryIndexedTree(int n_, T init = 0) : n(n_), bit(n_ + 1, init) {}
    BinaryIndexedTree(vector<T> init) : n(init.size() + 1), bit(init.size() + 1) {
        for (int i = 1; i < init.size() + 1; ++i) {
            bit[i] = init[i - 1];
        }
    }
    T sum(int i) {
        i++;
        T s = bit[0];
        for (int x = i; x > 0; x -= (x & -x))
            s += bit[x];
        return s;
    }
    void add(int i, T a) {
        i++;
        if (i == 0)
            return;
        for (int x = i; x <= n; x += (x & -x))
            bit[x] += a;
    }
    int lower_bound(int w) {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    int upper_bound(int w) {
        if (w < 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] <= w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // sum >= k * (r - l + 1);
    // sum_r - k * r >= sum_l - k * l;
    vl sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = a[i] + sum[i];
    }
    for (ll i = 1; i <= n; ++i) {
        sum[i] -= i * k;
    }
    vl sorted = sum;
    sort(sorted.begin(), sorted.end());
    BinaryIndexedTree<> bit(n + 1);
    ll ret = 0;
    for (int i = 0; i <= n; ++i) {
        int idx = lower_bound(sorted.begin(), sorted.end(), sum[i]) - sorted.begin();
        ret += bit.sum(idx);
        bit.add(idx, 1);
    }
    cout << ret << "\n";
    return 0;
}