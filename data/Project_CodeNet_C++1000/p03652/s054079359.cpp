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
    ll n,m;
    cin>>n>>m;
    vec<queue<ll>> a(n);
    REP(i,n){
        REP(j,m){
            ll aa;
            cin>>aa;
            a[i].push(aa);
        }
    }

    map<ll,ll> mp;
    ll ma=0;
    REP(i,n){
        ll v = a[i].front();
        mp[v]++;
        chmax(ma,mp[v]);
    }

    set<ll> st;
    ll ans=n;
    REP(i,m){
        auto it=mp.begin();
        while(it!=mp.end()){
            if(it->second==ma){
                st.insert(it->first);
                it=mp.erase(it);
            }else{
                it++;
            }
        }
        chmin(ans,ma);
        ma=0;
        bool flag=true;
        REP(j,n){
            if(st.find(a[j].front()) == st.end()){
                chmax(ma,mp[a[j].front()]);
                continue;
            }
            while(a[j].size() && st.find(a[j].front())!=st.end()) a[j].pop();
            if(a[j].empty()){
                flag=false;
                break;
            }
            mp[a[j].front()]++;
            chmax(ma,mp[a[j].front()]);
        }
        if(!flag) break;
    }
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