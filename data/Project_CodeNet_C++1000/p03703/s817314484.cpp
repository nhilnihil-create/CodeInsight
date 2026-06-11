#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template<class Monoid> struct SegmentTree {
private:
    using Func = std::function<Monoid(Monoid, Monoid)>;
    Func F;
    Monoid UNITY;
    int n;
    std::vector<Monoid> node;
public:
    SegmentTree() {}

    //m=size, f=[](M a,M b){return ;}
    // size : m
    SegmentTree(int m, const Func f, const Monoid &unity) {
        build(m, f, unity);
    }

    SegmentTree(const std::vector<Monoid>& v, const Func f, const Monoid &unity) {
        build(v, f, unity);
    }

    void build(int m, const Func f, const Monoid &unity) {
        F = f;
        UNITY = unity;
        n = 1; while (n < m) n <<= 1;
        node.resize(n * 2 - 1, UNITY);
    }

    void build(const std::vector<Monoid>& v, const Func f, const Monoid &unity) {
        F = f;
        UNITY = unity;
        int sz = v.size();
        n = 1; while (n < sz) n <<= 1;
        node.resize(n * 2 - 1, UNITY);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = F(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, Monoid val) {
        if (x >= n || x < 0) return;
        x += n - 1;
        node[x] = val;
        while (x > 0) {
            x = (x - 1) >> 1;
            node[x] = F(node[2 * x + 1], node[2 * x + 2]);
        }
    }
    // [a,b)
    Monoid get(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return UNITY;
        if (a <= l && r <= b) return node[k];
        Monoid vl = get(a, b, 2 * k + 1, l, (r - l) / 2 + l);
        Monoid vr = get(a, b, 2 * k + 2, (r - l) / 2 + l, r);
        return F(vl, vr);
    }

    Monoid operator[](int x)const {
        return node[n + x - 1];
    }

    int size() {
        return n;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            std::cout << i << "\t: " << node[n + i - 1] << std::endl;
        }
    }
};

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    vector<ll> sum(n + 1); // [0:i)
    sum[0] = 0;
    map<ll, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
        mp[sum[i + 1]] = -1;
    }
    int t = 0;
    for (auto p : mp) {
        mp[p.first] = t++;
    }
    SegmentTree<ll> seg(t, [](int a, int b) {return a + b; }, 0);
    ll ans = 0;
    for (int i = n; i >= 0; i--) {
        ans += seg.get(mp[sum[i]], t);
        seg.update(mp[sum[i]], seg[mp[sum[i]]] + 1);
    }
    cout << ans << endl;
    return 0;
}