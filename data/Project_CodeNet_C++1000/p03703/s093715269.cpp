#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n = 0) : n(_n), bit(n + 1) {}

    // sum of [0, i), 0 <= i <= n
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // 0 <= i < n
    void add(int i, T x) {
        ++i;
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    //[l, r) 0 <= l < r < n
    T sum(int l, int r) { return sum(r) - sum(l); }
};

int main() {
    int N, K;
    cin >> N >> K;
    V<ll> a(N);
    ll s = 0;
    rep(i, N) {
        ll x;
        cin >> x;
        s += x;
        a[i] = s - (ll)(i + 1) * K;
    }
    V<ll> xs = a;
    xs.pb(0);
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    debug(a);

    auto get = [&](ll x) { return lower_bound(ALL(xs), x) - xs.begin(); };

    BIT<ll> T(N + 1);
    T.add(get(0ll), 1);

    ll ans = 0;
    rep(i, N) {
        int p = get(a[i]);
        ans += T.sum(0, p + 1);
        T.add(p, 1);
    }
    cout << ans << endl;

    return 0;
}