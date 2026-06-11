#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;
struct E {
  int u,v,c;
  E(int u,int v,int c):u(u),v(v),c(c){}
};

const ll inf = -1e18L;
vector<int> g[2][1000];
bool used[2][1000];
void dfs(int x, int u){
  if(used[x][u]) return;
  used[x][u] = true;
  for(int v:g[x][u]) dfs(x,v);
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<E> e;
  rep(i,m){
    int u,v,c;
    cin >> u >> v >> c;
    --u, --v;
    e.emplace_back(u,v,c);
    g[true][u].emplace_back(v);
    g[false][v].emplace_back(u);
  }
  dfs(true,0);
  dfs(false,n-1);
  vector<bool> b(n);
  rep(i,n) b[i] = used[true][i] && used[false][i];

  vector<ll> d(n,inf);
  d[0] = 0;
  rep(c,n+1){
    bool upd = false;
    rep(i,m){
      int u=e[i].u, v=e[i].v, c=e[i].c;
      if(!b[u] || !b[v]) continue;
      if(d[v] < d[u]+c){
        d[v] = d[u]+c;
        upd = true;
      }
    }
    if(!upd) break;
    if(c==n){
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << d[n-1] << endl;
}