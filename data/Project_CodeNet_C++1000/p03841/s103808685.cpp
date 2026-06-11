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
    ll n;
    cin>>n;
    Array x(n);
    REP(i,n) cin>>x[i];

    vec<P> a; 
    REP(i,n){
        a.push_back({x[i],i});
    }
    sort(all(a));

    Array ans(n*n,-1);
    int pos=0;
    int ret=0;
    int pre=-1;
    vec<P> nokori;
    REP(i,n){
        int now=a[i].first;
        ll num=a[i].second;
        now--;
        if(ans[now]!=-1){
            cout<<"No"<<en;
            return;
        }
        ans[now]=num+1;
        ret += now-pre-1;
        //cout<<ret<<" "<<num<<en; 
        if(ret < num){
            cout<<"No"<<en;
            return;
        }
        REP(k, num){
            while(ans[pos]!=-1) pos++;
            if(ans[pos] == -1){
                ans[pos] = num+1;
            }
        }
        ret-=num;
        pre=now;
        REP(j, n-1-num) nokori.push_back({now, num+1});
    }

    reverse(all(nokori));
    pos = n*n-1;
    REP(i,nokori.size()){
        int now = nokori[i].first;
        ll num = nokori[i].second;
        while(ans[pos]!=-1) pos--;
        if(pos<now){
            cout<<"No"<<en;
            return;
        }
        ans[pos]=num;
    }

    cout<<"Yes"<<en;
    for(auto i:ans) cout<<i<<" ";
    cout<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}