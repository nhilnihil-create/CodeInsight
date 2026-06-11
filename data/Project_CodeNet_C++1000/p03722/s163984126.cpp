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

struct Edge {
    ll to, rev;
    long double cap;
    Edge(ll _to, long double _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,
              long double revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

//最短経路（負閉路検出）Eが小さい時
void BellmanFord(Graph &G, ll s, Array &d, Array &negative) { //O(|E||V|)
    d.resize(G.size());
    negative.resize(G.size());
    REP(i, d.size())
    d[i] = INF;
    REP(i, d.size())
    negative[i] = false;
    d[s] = 0;
    REP(k, G.size() - 1) {
        REP(i, G.size()) {
            REP(j, G[i].size()) {
                if(d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
                    d[G[i][j].to] = d[i] + G[i][j].cap;
                }
            }
        }
    }
    REP(k, G.size() - 1) {
        REP(i, G.size()) {
            REP(j, G[i].size()) {
                if(d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
                    d[G[i][j].to] = d[i] + G[i][j].cap;
                    negative[G[i][j].to] = true;
                }
                if(negative[i] == true)
                    negative[G[i][j].to] = true;
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        add_edge(g, a, b, -c, false, 0);
    }

    Array d, negative;
    BellmanFord(g, 0, d, negative);
    if(negative[n - 1]) {
        cout << "inf" << en;
    } else {
        cout << -d[n - 1] << en;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    // ll t;cin>>t;REP(i,t) solve();

    return 0;
}
