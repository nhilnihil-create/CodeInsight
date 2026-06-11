#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename Iter, typename T> int gt(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L; }
template <typename Iter, typename T> int ge(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L; }
template <typename Iter, typename T> int lt(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L - 1; }
template <typename Iter, typename T> int le(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L - 1; }
template <typename Bst, typename T> typename Bst::const_iterator gt(const Bst& bst, T v) { return bst.upper_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator ge(const Bst& bst, T v) { return bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator lt(const Bst& bst, T v) { return bst.lower_bound(v) == bst.begin() ? bst.end() : --bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator le(const Bst& bst, T v) { return bst.upper_bound(v) == bst.begin() ? bst.end() : --bst.upper_bound(v); }
// NOTE: one-indexed
template <typename T> struct bit {
    const int n;
    vector<T> t;
    bit(int n) : n(n), t(n + 1) {}
    void add(int i, T value) {
        for(int j = i; j <= n; j += j & -j) {
            t[j] += value;
        }
    }
    T sum(int i) {
        T res = 0;
        for(int j = i; j > 0; j -= j & -j) {
            res += t[j];
        }
        return res;
    }
    T sum(int L, int R) {
        return sum(R) - sum(L - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    partial_sum(a.begin(), a.end(), a.begin());
    set<ll> values;
    for(int i = 0; i <= n; i++) {
        values.insert(a[i] -= k * i);
    }
    map<ll, int> comp;
    int id = 1;
    for(ll x : values) {
        comp[x] = id++;
    }
    bit<int> b(id);
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += b.sum(comp[a[i]]);
        b.add(comp[a[i]], 1);
    }
    cout << ans << endl;
    return 0;
}
