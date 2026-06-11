#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
  #include "header.h"
#else
  #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
  return;
}

vi vis, col;
vector<vi> adj;
int cc = 0, odd = 0;
void dfs(int v, int par = -1) {
  //debug(v, par);
  if(par != -1) {
    col[v] = !col[par];
  }
  vis[v] = 1;
  cc++;
  for(auto x: adj[v]) {
    if(x == par) continue;
    if(vis[x]) {
      if(col[x] == col[v]) {
        odd = 1;
      }
      continue;
    }
    dfs(x, v);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int n, m; cin>>n>>m;
  col.resize(n+1);
  vis.resize(n+1);
  adj.resize(n+1, vi(0));
  rep(i,0,m) {
    int u, v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int c1, c2, c3;
  c1 = c2 = 0;
  c3 = 0;
  rep(i,1,n+1) {
    if(!vis[i]) {
      col[i] = 0;
      odd = 0;
      cc = 0;
      dfs(i, -1);
      debug(i, cc);
      if(cc == 1) c3++;
      else if(odd) c1++;
      else c2++;
    }
  }
  lli kk = 2*c3*1LL*n - (c3*1LL*(c3-1)) - c3;
  debug(c3, kk, c1, c2);
  cout<<2*c1*1LL*c2 + c1*1LL*c1 + 2*c2*1LL*c2 + kk<<endl;
}

