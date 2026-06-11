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

vector<P> g[200];
int d[8][8];
int r;
int dfs(int u=-1,int b=0){
  if(b==(1<<r)-1) return 0;
  int res = 1e9;
  rep(v,r){
    if(b>>v&1)continue;
    res = min(res,dfs(v,b|(1<<v))+d[u][v]);
  }
  return res;
}
int main() {
  int n,m;
  cin >> n >> m >> r;
  vector<int> t(r);
  rep(i,r) cin >> t[i], --t[i];
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }
  rep(i,r){
    vector<int> di(n,1e9);
    queue<P> q;
    auto push = [&](int nd,int v){
      if(di[v]<=nd) return;
      di[v] = nd;
      q.emplace(nd,v);
    };
    push(0,t[i]);
    while(!q.empty()){
      P u = q.front(); q.pop();
      for(auto v:g[u.second]) push(u.first+v.second,v.first);
    }
    rep(j,r) d[i][j] = di[t[j]];
  }
  cout << dfs() << endl;
}