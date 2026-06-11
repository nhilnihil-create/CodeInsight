#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[200004];
    ll s[200004];
    P p[200004];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= k;
        s[i] = a[i];
        if(i > 0) s[i] += s[i - 1];
        if(s[i] >= 0) ans++;
        p[i] = P(s[i], i);
    }
    sort(p, p + n);
    int nth[200004];
    for(int i = 0; i < n; i++) nth[p[i].second] = i;
    SegmentTree<ll> seg(n, [](ll a, ll b){return a + b;}, (ll)0);
    for(int i = 0; i < n; i++) seg.set(i, (ll)0);
    seg.build();
    for(int i = n - 1; i >= 0; i--){
        int insert = lower_bound(p, p + n, P(s[i], -1)) - p;
        ans += seg.query(insert, n);
        seg.update(nth[i], 1);
    }
    cout << ans << endl;
}