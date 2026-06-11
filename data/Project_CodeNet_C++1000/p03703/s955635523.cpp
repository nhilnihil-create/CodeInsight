#ifdef LOCAL
//#define _GLIBCXX_DEBUG
#endif
//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<char> Vc;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;
typedef vector<vector<char>> VVc;
typedef vector<vector<vector<ll>>> VVV;
typedef vector<vector<vector<vector<ll>>>> VVVV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define rEach(i, mp) for (auto i = mp.rbegin(); i != mp.rend(); ++i)
#ifdef LOCAL
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgset(st) cerr << #st << ":"<<endl; for (auto i = st.begin(); i != st.end(); ++i) { cerr << *i <<" ";}cerr<<endl;
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#else
#define dbg(...)
#define dbgmap(...)
#define dbgset(...)
#define dbgarr(...)
#define dbgdp(...)
#endif
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,v.size())i>>v[j];return i;}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

    int sz, height;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h,
                    const Monoid &M1, const OperatorMonoid OM0)
            : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while(sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if(lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid reflect(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
    }

    inline void thrust(int k) {
        for(int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), ++l;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, reflect(l++));
            if(r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }

    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            propagate(a);
            Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
            if(check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, reflect(a));
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1) {
                Monoid nxt = f(reflect(--b), R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

    void debug(ll n){
        Vec v;
        rep(i,n){
            v.pb(query(i,i+1));
        }
        dbg(v);
    }
};


int solve(){
    ll n,k;
    cin>>n>>k;
    Vec a(n);
    cin>>a;
    Vec s(n+1);
    rep(i,n) s[i+1] = a[i] + s[i];
    Vec v(n+1);
    rep(i,n+1){
        v[i] = s[i]-k*i;
    }
    dbg(s);
    dbg(v);
    VP vp;
    rep(i,n+1){
        vp.emplace_back(v[i],i);
    }

    auto comp = [](P a, P b){
        if(b.fi == a.fi){
            return a.second < b.second;
        }else{
            return a.fi < b.fi;
        }
    };
    sort(ALL(vp),comp);
    auto f = [](ll a, ll b) { return a + b; };
    LazySegmentTree<ll> seg(n, f, f,  f, 0, 0);
    ll ans = 0;
    rep(i,n+1){
        ll ind = vp[i].se;
        ans += seg.query(0,ind);
        seg.update(ind,ind+1,1);
    }
    out(ans);

    return  0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);
    solve();
}
