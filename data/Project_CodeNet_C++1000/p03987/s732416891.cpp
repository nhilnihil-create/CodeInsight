#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define INF (ll)(1e18)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }



template<typename T>
class SegTree {
    int n;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;
    vector<T> data;
    
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(c1, c2);
    }
    
public:
    SegTree<T>(int _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
    : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) n *= 2;
        data = vector<T>(2 * n - 1, def);
    }
    
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
    
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    
    T operator[](int i) { return data[i + n - 1]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n;
    cin >> n;
    SegTree<int> sgt(n, n,
                     [](int a, int b) { return min(a, b); },
                     [](int a, int b) { return b; });
    SegTree<int> sgt2(n, -1,
                     [](int a, int b) { return max(a, b); },
                     [](int a, int b) { return b; });
    
    vector<pii> v(n);
    rep(i, n) cin >> v[i].F;
    rep(i, n) v[i].S = i;
    
    sort(all(v));
    
    ll ans = 0;
    rep(i, n) {
        ans += (ll)v[i].F * (sgt.query(v[i].S, n) - v[i].S) * (v[i].S - sgt2.query(0, v[i].S));
        // cout << endl << sgt.query(0, v[i].S) << " " << sgt.query(v[i].S, n) << endl;
        // cout << sgt2.query(0, v[i].S) << " " << sgt2.query(v[i].S, n) << endl;
        sgt.change(v[i].S, v[i].S);
        sgt2.change(v[i].S, v[i].S);
    }
    cout << ans << endl;
}
