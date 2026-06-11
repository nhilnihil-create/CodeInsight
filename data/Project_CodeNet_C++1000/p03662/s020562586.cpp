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

const int maxn = 100010;

V<int> g[maxn];
int sz[maxn], par[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    par[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int main() {
    int N;
    cin >> N;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    V<int> vs;
    int v = N - 1;
    while (v != -1) {
        vs.pb(v);
        v = par[v];
    }
    reverse(ALL(vs));
    int len = vs.size();
    debug(vs);
    int b = sz[vs[(len + 1) / 2]], a = N - b;
    puts(a > b ? "Fennec" : "Snuke");

    return 0;
}