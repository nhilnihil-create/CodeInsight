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
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

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
    int H, W, N;
    cin >> H >> W >> N;

    set<pii> st;
    map<pii, int> T;

    rep(i, N) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        st.insert(mp(a, b));
    }

    for (auto p : st) {
        int x, y;
        tie(x, y) = p;
        for (int i = x - 2; i <= x; ++i) {
            for (int j = y - 2; j <= y; ++j) {
                if (i >= 0 && j >= 0 && i + 3 <= H && j + 3 <= W) {
                    T[mp(i, j)]++;
                }
            }
        }
    }
    V<ll> ans(10);
    ans[0] = (ll)(H - 2) * (W - 2) - T.size();
    for (auto pr : T) {
        ans[pr.se]++;
    }
    rep(i, 10) { cout << ans[i] << endl; }

    return 0;
}