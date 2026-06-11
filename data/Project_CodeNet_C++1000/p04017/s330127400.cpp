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
using tp = tuple<ll, ll, ll>;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
//constexpr long long MOD = (ll)1e9 + 7;
constexpr long long MOD = 998244353LL;
using ld = long double;
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

//グラフ関連
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
    ll n;
    cin >> n;
    vec<ll> x(n);
    REP(i, n) {
        cin >> x[i];
    }

    ll l;
    cin >> l;
    vvec<ll> next(20, vec<ll>(n, 0));
    REP(i, n) {
        auto it = upper_bound(all(x), x[i] + l);
        it--;
        next[0][i] = it - x.begin();
    }

    REP(i, 19) {
        REP(j, n) {
            next[i + 1][j] = next[i][next[i][j]];
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b)
            swap(a, b);

        ll ans = n;
        ll con = 0;
        int now = a;
        REP2(i, 20) {
            if(next[i][now] < b) {
                con += 1LL << i;
                now = next[i][now];
            } else {
                chmin(ans, con + (1LL << i));
            }
        }
        cout << ans << en;
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
