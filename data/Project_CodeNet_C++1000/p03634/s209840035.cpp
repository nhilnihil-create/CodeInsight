#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = struct{int to;ll cost;};
const int limit = 100000+10;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
vector<edge>tree[limit];
ll depth[limit];

void dfs(int v,int p,ll d){
  depth[v] = d;
  for(auto &e:tree[v]){
    if(e.to == p) continue;
    dfs(e.to,v,d+e.cost);
  }
}

int main() {
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }
  int q,k;
  cin >> q >> k;
  k--;
  dfs(k,-1,0);
  rep(i,q){
    int x,y;
    cin >> x >> y;
    x--;y--;
    cout << depth[x]+depth[y] << endl;
  }
}
