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

int main() {
    int n, m;
    cin >> n >> m;
    V<int> a(n);
    rep(i, n) cin >> a[i], --a[i];
    V<int> prf(m + 1);
    rep(i, n - 1) {
        if (a[i] < a[i + 1]) {
            prf[a[i] + 1]++;
            prf[a[i + 1]]--;
        } else {
            prf[a[i] + 1]++;
            prf[m]--;
            prf[0]++;
            prf[a[i + 1]]--;
        }
    }

    rep(i, m) prf[i + 1] += prf[i];

    ll s = 0;

    {
        rep(i, n - 1) {
            ll c1 = (a[i + 1] - a[i] + m) % m;
            ll c2 = (a[i + 1] - 0 + m) % m + 1;
            s += min(c1, c2);
        }
    }

    VV<int> idx(m);
    for (int i = 1; i < n; ++i) {
        idx[a[i]].pb(i);
    }

    ll ans = s;

    for (int x = 0; x < m - 1; ++x) {  // x -> x+1
        s -= prf[x];
        for (int i : idx[x]) {
            s += (a[i] - a[i - 1] + m) % m - 1;
        }
        chmin(ans, s);
    }
    cout << ans << endl;

    return 0;
}