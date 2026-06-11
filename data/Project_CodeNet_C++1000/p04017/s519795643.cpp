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

const int maxn = 100010;
int nxt[20][maxn];

int main() {
    int n;
    cin >> n;
    V<int> x(n);
    rep(i, n) cin >> x[i];
    int L, Q;
    cin >> L >> Q;

    rep(i, n) {
        int p = upper_bound(ALL(x), x[i] + L) - x.begin();
        nxt[0][i] = p - 1;
    }

    rep(i, 19) {
        rep(j, n) {
            nxt[i + 1][j] = (nxt[i][j] == n - 1 ? n - 1 : nxt[i][nxt[i][j]]);
        }
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int j = 19; j >= 0; --j) {
            if (nxt[j][a] < b) {
                ans |= (1 << j);
                a = nxt[j][a];
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}