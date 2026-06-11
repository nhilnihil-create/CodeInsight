#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
//constexpr long long MOD = 998244353LL;
//constexpr long long MOD = 1777777777LL;
using ld = long double;
using tp = tuple<ll, ll, ll>;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

// long dobule
struct Edge {
    ll to, cap, rev;
    Edge(ll _to, ll _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph &G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vvec<int> g(n + 1, vec<int>(26, -1));
    vec<int> pre(26, -1);
    REP2(i, n) {
        REP(j, 26) {
            g[i + 1][j] = pre[j];
        }
        pre[s[i] - 'a'] = i + 1;
    }

    REP(j, 26) {
        g[0][j] = pre[j];
    }

    vec<ll> dp(n + 1, -1);

    auto dfs = [&](auto &&self, int i) -> int {
        if(dp[i] != -1)
            return dp[i];

        int ret = INF_INT;
        REP(j, 26) {
            if(g[i][j] == -1) {
                return dp[i] = 1;
            } else {
                chmin(ret, self(self, g[i][j]) + 1);
            }
        }
        return dp[i] = ret;
    };

    dfs(dfs, 0);

    int pos = 0;
    while(pos != -1) {
        REP(j, 26) {
            if(g[pos][j] == -1) {
                cout << (char)('a' + j) << en;
                pos = -1;
                break;
            }
            if(dp[pos] == dp[g[pos][j]] + 1) {
                cout << (char)('a' + j);
                pos = g[pos][j];
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    ll t;
    cin >> t;
    while(t--)*/
    solve();

    return 0;
}
