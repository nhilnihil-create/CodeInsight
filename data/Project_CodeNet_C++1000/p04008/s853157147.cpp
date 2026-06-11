#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);++i)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);--i)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
//constexpr long long MOD = 998244353LL;
using ld=long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void solve(){
    ll n,k;
    cin>>n>>k;
    Array a(n);
    Array in(n,0);
    REP(i,n){
        cin>>a[i];
        a[i]--;
    }

    if(n+1<=k){
        ll ans=0;
        if(a[0]) ans++;
        cout<<ans<<en;
        return;
    }

    if(k==1){
        ll ans=0;
        REP(i,n) if(a[i]) ans++;
        cout<<ans<<en;
        return;
    }

    ll ans=0;
    if(a[0]) ans++;
    a[0]=0;

    Graph g(n);

    rep(i,1,n){
        add_edge(g,a[i],i,1,false,1);
    }

    auto dfs =[&](auto &&self, int v)->ll{
        ll d=0;
        for(auto e:g[v]){
            chmax(d,self(self,e.to)+1);
        }
        if(d==k-1){
            if(a[v]){
                a[v]=0;
                ans++;
            }
            return -1;
        }
        return d;
    };

    dfs(dfs,0);
    cout<<ans<<en;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}
