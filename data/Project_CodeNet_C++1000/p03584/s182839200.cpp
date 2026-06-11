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
	ll to, cap, rev, col;
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

void Dijkstra(Graph& G, ll s, Array& d) {//O(|E|log|V|)
  d.resize(G.size());
  REP(i, d.size())d[i] = INF;
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    P a = q.top();
    q.pop();
    if (d[a.second] < a.first)continue;
    REP(i, G[a.second].size()) {
      Edge e = G[a.second][i];
      if (d[e.to] > d[a.second] + e.cap) {
        d[e.to] = d[a.second] + e.cap;
        q.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

bool tsort(Graph& graph, Array& order) { 
 int n = graph.size(), k = 0;
 Array in(n);
 for (auto& es : graph)
  for (auto& e : es)in[e.to]++;
 priority_queue<ll, Array, greater<ll>> que;
 REP(i, n)
  if (in[i] == 0)que.push(i);
 while (que.size()) {
  int v = que.top();
  que.pop();
  order.push_back(v);
  for (auto& e : graph[v])
   if (--in[e.to] == 0)que.push(e.to);
 }
 if (order.size() != n)return false;
 else return true;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    Array a(n),b(n);
    REP(i,n) cin>>a[i]>>b[i];

    auto check = [&]()->ll{
        ll sum=0;
        REP(i,n){
            if((~k)&a[i]) continue;
            sum+=b[i];
        }
        return sum;
    };

    ll ans=check();

    REP(r,30){
        if(k>>r&1){
            k-=(1LL<<r);
            chmax(ans,check());
        }
        k+=(1LL<<r);
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
