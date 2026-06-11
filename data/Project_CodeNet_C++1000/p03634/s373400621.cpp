#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cout << a[i] << " "; cout << "\n" << flush; }
ll dbgt = 1; void err() { cout << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cout<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 5e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//
// Lowest Common Ancestor by binary lifting
template <typename T>  // T: type of cost
struct lca {
    ll n, root, l;
    vector<vector<ll>> to;
    vector<vector<T>> co;
    vector<ll> dep;
    vector<T> costs;
    vector<vector<ll>> par;

    lca(ll n) : n(n), to(n), co(n), dep(n), costs(n) {
        l = 0;
        while ((1 << l) < n) ++l;
        par = vector<vector<ll>>(n + 1, vector<ll>(l, n));
    }
    void addEdge(ll a, ll b, T c = 0) {
        to[a].emplace_back(b);
        co[a].emplace_back(c);
        to[b].emplace_back(a);
        co[b].emplace_back(c);
    }
    void dfs(ll v, ll d = 0, T c = 0, ll p = -1) {
        if (p != -1) par[v][0] = p;
        dep[v] = d;
        costs[v] = c;
        for (ll i = 0; i < to[v].size(); ++i) {
            ll u = to[v][i];
            if (u == p) continue;
            dfs(u, d + 1, c + co[v][i], v);
        }
    }

    void init(ll _root = 0) {
        root = _root;
        dfs(root);
        for (ll i = 0; i < l - 1; ++i) {
            for (ll v = 0; v < n; ++v) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }
    // LCA
    ll operator()(ll a, ll b) {
        if (dep[a] > dep[b]) swap(a, b);
        ll gap = dep[b] - dep[a];
        for (ll i = l - 1; i >= 0; --i) {
            ll len = 1 << i;
            if (gap >= len) {
                gap -= len;
                b = par[b][i];
            }
        }
        if (a == b) return a;
        for (ll i = l - 1; i >= 0; --i) {
            ll na = par[a][i];
            ll nb = par[b][i];
            if (na != nb) a = na, b = nb;
        }
        return par[a][0];
    }
    ll length(ll a, ll b) {
        ll c = lca::operator()(a, b);
        return dep[a] + dep[b] - dep[c] * 2;
    }
    T dist(ll a, ll b) {
        ll c = lca::operator()(a, b);
        return costs[a] + costs[b] - costs[c] * 2;
    }
};

int main() {
    init();
    ll N;
    cin >> N;
    lca<ll> L(N);
    rep(i,N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        L.addEdge(a, b, c);
    }
    L.init();
    
    ll Q, K;
    cin >> Q >> K;
    K--;
    rep(i,Q){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cout << L.dist(x, K) + L.dist(y, K) << '\n';
    }
}