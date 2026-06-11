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

const int maxn = 200010;
int nxt[26][maxn];
int dp[maxn];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    rep(c, 26) nxt[c][n] = n + 1;
    for (int i = n - 1; i >= 0; --i) {
        rep(c, 26) nxt[c][i] = nxt[c][i + 1];
        nxt[s[i] - 'a'][i] = i;
    }

    for (int i = n - 1; i >= 0; --i) {
        int m = -1;
        rep(c, 26) chmax(m, nxt[c][i]);
        if (m == n + 1) {
            dp[i] = 0;
        } else {
            dp[i] = dp[m + 1] + 1;
        }
    }

    string ans;
    int len = dp[0] + 1;
    int p = 0;

    while (len--) {
        rep(c, 26) {
            if (nxt[c][p] == n + 1 || dp[nxt[c][p] + 1] == len - 1) {
                ans.pb('a' + c);
                p = nxt[c][p] + 1;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}