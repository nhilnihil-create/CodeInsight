#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

struct UnionFind{
    // par[i] parent. if i == par[i] i is root
    vector<ll> par;
    // sizes[i] sizeof tree i if i is root
    vector<ll> sizes;

    UnionFind(ll n) : par(n), sizes(n, 1){
        // init: all node is root i
        rep(i, n) par[i] = i;
    }

    // find root of x
    ll find(ll x){
        if (x == par[x])
            return x;
        return par[x] = find(par[x]); // recursive, editing root
    }

    // merge x, y
    void unite(ll x, ll y){
        // root
        x = find(x);
        y = find(y);

        // do not merge if same tree
        if (x == y)
            return;

        // force size x > y
        if (sizes[x] < sizes[y])
            swap(x, y);

        // unite: x is parent of y
        par[y] = x;
        sizes[x] += sizes[y];
    }

    // x, y same root
    bool same(ll x, ll y){
        return find(x) == find(y);
    }

    // size of tree containing x
    ll size(ll x){
        return sizes[find(x)];
    }
};

vll a;
vll b;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, k, l;
    cin >> n >> k >> l;
    UnionFind uf1(n);
    UnionFind uf2(n);
    a.resize(n);
    b.resize(n);
    rep(i, k){
        ll p, q;
        cin >> p >> q;
        p--, q--;
        uf1.unite(p, q);
    }
    rep(i, l){
        ll r, s;
        cin >> r >> s;
        r--, s--;
        uf2.unite(r, s);
    }
    rep(i, n){
        a[i] = uf1.find(i);
        b[i] = uf2.find(i);
    }
    map<pll, ll> ans;
    rep(i, n){
        ans[make_pair(a[i], b[i])]++;
    }
    rep(i, n){
        cout << ans[make_pair(a[i], b[i])] << " \n"[i==n-1];
    }
    return 0;
}