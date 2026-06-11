//#define _DEBUG
#include "bits/stdc++.h"
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif
#define rep(index,num) for(int index=0;index<(int)num;index++)
#define rep1(index,num) for(int index=1;index<=(int)num;index++)
#define brep(index,num) for(int index=(int)num-1;index>=0;index--)
#define brep1(index,num) for(int index=(int)num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=(ll)1e+18+1;
int INF=1e+9+1;
using Graph = vector<vpll>;

class lca {
public:
  int n;
  int log2_n;
  vector<vint> parent;//parent[k][v]:vから2^k回遡った親
  vector<int> depth;
  vector<vll> weight;//weight[k][v]:vから2^k回遡った親までの距離
  vector<vll> wmax;//wmax[k][v]:vから2^k回遡った親までの辺の重みの最大値

  lca() {}

  lca(const Graph &g, int root)
      : n(g.size()), log2_n(log2(n) + 2), parent(log2_n, vint(n)),
        depth(n),weight(log2_n,vll(n)),wmax(log2_n,vll(n)) {
    dfs(g, root, -1, 0,0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < (int)g.size(); v++) {
        if (parent[k][v] < 0){
			parent[k + 1][v] = -1;
			weight[k + 1][v] = 0;
			wmax[k+1][v]=-1;
		}
        else{
			parent[k + 1][v] = parent[k][parent[k][v]];
			weight[k + 1][v] = weight[k][v] + weight[k][parent[k][v]];
			wmax[k + 1][v] = max(wmax[k][v],wmax[k][parent[k][v]]);
		}
      }
    }
  }

  void dfs(const Graph &g, int v, int p, int d,ll w) {
    parent[0][v] = p;
    depth[v] = d;
	weight[0][v]=w;
	wmax[0][v]=w;
    for (auto &e : g[v]) {
      if (e.first != p)
        dfs(g, e.first, v, d + 1, e.second);
    }
  }

  int get(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
  ll getweight(int u, int v) {
	  ll sum=0;
	  if (depth[u] > depth[v])
		swap(u, v);
	  for (int k = 0; k < log2_n; k++) {
		if ((depth[v] - depth[u]) >> k & 1) {
		  sum+=weight[k][v];
		  v = parent[k][v];
		}
	  }
	  if (u == v)
		return sum;
	  for (int k = log2_n - 1; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
		  sum+=weight[k][u]+weight[k][v];
		  u = parent[k][u];
		  v = parent[k][v];
		}
	  }
	  return sum+weight[0][u]+weight[0][v];
  }
  ll getwmax(int u, int v) {
	ll ans=0;
	if (depth[u] > depth[v])
	  swap(u, v);
	for (int k = 0; k < log2_n; k++) {
	  if ((depth[v] - depth[u]) >> k & 1) {
		ans=max(ans,wmax[k][v]);
		v = parent[k][v];
	  }
	}
	if (u == v)
	  return ans;
	for (int k = log2_n - 1; k >= 0; k--) {
	  if (parent[k][u] != parent[k][v]) {
		ans=max({ans,wmax[k][u],wmax[k][v]});
		u = parent[k][u];
		v = parent[k][v];
	  }
	}
	return max({ans,weight[0][u],weight[0][v]});
  }
};
int main(){
	int N;
	scan(N);
	Graph adj(N);
	rep(i,N-1){
		int a,b;
		ll c;
		scan(a>>b>>c);
		a--; b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	lca l(adj,0);
	int Q,K;
	scan(Q>>K);
	K--;
	rep(i,Q){
		int x,y;
		scan(x>>y);
		x--; y--;
		prin(l.getweight(x,K)+l.getweight(K,y));
	}
	return 0;
}
