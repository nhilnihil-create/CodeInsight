#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

/*
    vector<long long> a(n) を座圧する場合 :
    auto v = compress(a);
    auto m = dict(v);
    i番目の要素の取り出し方 :
    m[a[i]]
*/
template <typename T>
vector<T> compress(vector<T> vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template <typename T>
map<T, int> dict(vector<T>& vec) {
    map<T, int> res;
    for (int i = 0; i < (int)vec.size(); i++) {
        res[vec[i]] = i;
    }
    return res;
}

/*
    1-indexed であることに注意 !!
*/
template <typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n) : n(n), dat(n + 1, 0) {}

    T sum(int a) {
        T res = 0;
        for (int i = a; i > 0; i -= (i & (-i))) res += dat[i];
        return res;
    }

    T sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    void add(int k, T x) {
        if (k == 0) return;
        for (int i = k; i <= n; i += (i & (-i))) dat[i] += x;
    }

    /*
        a[0] + a[1] + ... + a[res] >= x
    */
    int lower_bound(T x) {
        if (x <= 0) return T(0);
        int res = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (res + k <= n && dat[res + k] < x) {
                x -= dat[res + k];
                res += k;
            }
        }
        return res + 1;
    }
};

signed main() {
    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) {
        cin >> a[i];
        a[i] -= k;
    }
    rep(i, n - 1) {
        a[i + 1] += a[i];
    }
    vector<ll> v;
    v.emplace_back(0);
    rep(i, n) {
        v.emplace_back(a[i]);
    }
    auto c = compress(v);
    auto m = dict(c);
    ll ans = 0;
    BIT<int> bit(m.size() + 1);
    bit.add(m[0] + 1, 1);
    rep(i, n) {
        ans += bit.sum(0, m[a[i]] + 1 + 1);
        bit.add(m[a[i]] + 1, 1);
    }
    cout << ans << endl;
    return 0;
}