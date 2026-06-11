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

bool ask(ll n) {
    printf("? %lld\n", n);
    fflush(stdout);
    string s;
    cin >> s;
    return s == "Y";
}

void answer(ll n) {
    printf("! %lld\n", n);
    exit(0);
}

int main() {
    bool ten = ask(TEN(9));
    if (ten) {
        for (int i = 1;; ++i) {
            ll x = 5 * TEN(i - 1);
            bool r = ask(x);
            if (r) {
                answer(TEN(i - 1));
            }
        }
    } else {
        int k;
        for (k = 1;; ++k) {
            ll x = TEN(k - 1);
            bool r = ask(x);
            if (!r) {
                k--;
                break;
            }
        }
        ll lo = TEN(k - 1) - 1, hi = TEN(k);
        while (hi - lo > 1) {
            ll m = (lo + hi) / 2;
            if (ask(m * 10)) {
                hi = m;
            } else {
                lo = m;
            }
        }
        answer(hi);
    }
    return 0;
}