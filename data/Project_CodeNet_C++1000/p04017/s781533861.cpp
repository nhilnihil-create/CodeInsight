#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1e9+7; // 998244353
const ll INF = 1e18;
const int MX = 1e5+5;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void sc(complex<T>& x);
    template<class T1, class T2> void sc(pair<T1,T2>& p);
    template<class T> void sc(vector<T>& a);
    template<class T, size_t SZ> void sc(array<T,SZ>& a);

    template<class T> void sc(T& x) { cin >> x; }
    void sc(double& x) { string t; sc(t); x = stod(t); }
    void sc(ld& x) { string t; sc(t); x = stold(t); }
    template<class Arg, class... Args> void sc(Arg& first, Args&... rest) { 
        sc(first); sc(rest...); 
    }

    template<class T> void sc(complex<T>& x) { T a,b; sc(a,b); x = cd(a,b); }
    template<class T1, class T2> void sc(pair<T1,T2>& p) { sc(p.f,p.s); }
    template<class T> void sc(vector<T>& a) { F0R(i,sz(a)) sc(a[i]); }
    template<class T, size_t SZ> void sc(array<T,SZ>& a) { F0R(i,SZ) sc(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

ll a[MX], par[MX][20];

int main() {
    setIO();
    int n; sc(n);
    F0R(i,n) sc(a[i]);
    int l; sc(l);
    F0R(i,n) par[i][0] = lower_bound(a,a+n,a[i]+l+1)-a-1;
    FOR(i,1,20) F0R(j,n) par[j][i] = par[par[j][i-1]][i-1];
    int q; sc(q);
    F0R(i,q) {
        int u,v; sc(u,v); 
        u--; v--; if (u > v) swap(u,v);
        int w = u, ans = 0;
        F0Rd(i,20) {
            if (par[w][i] < v) {
                ans += (1<<i);
                w = par[w][i];
            }
        }
        ps(ans+1);
    }
	return 0;
}