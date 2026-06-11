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

void solve() {
    ll n, m;
    cin >> n >> m;
    vec<ll> x(n);
    map<ll, ll> mp;
    vec<ll> con(m, 0);
    vec<ll> pairs(m, 0);
    REP(i, n) {
        cin >> x[i];
        con[x[i] % m]++;
        mp[x[i]]++;
    }
    for(auto i : mp) {
        pairs[i.first % m] += i.second / 2;
    }

    ll ans = 0;
    REP(i, m) {
        int j = (m - i) % m;
        if(i > j)
            break;
        else if(i == j) {
            ans += con[i] / 2;
        } else {
            ll t = min(con[i], con[j]);
            ans += t;
            ans += min((con[i] - t) / 2, pairs[i]);
            ans += min((con[j] - t) / 2, pairs[j]);
        }
    }
    cout << ans << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    /*
    ll t;
    cin >> t;
    REP(i, t)
    solve();
    */

    return 0;
}
