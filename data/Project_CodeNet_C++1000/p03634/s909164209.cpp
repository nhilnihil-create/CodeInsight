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
using P = pair<ll,ll>;

vector<P> g[100005];
int main() {
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b,c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }
  int m,k;
  cin >> m >> k;
  --k;
  vector<ll> d(n,1e18L);
  priority_queue<P,vector<P>,greater<P>> q;
  auto push = [&](int v, ll nd){
    if(d[v]<=nd)return;
    d[v]=nd;
    q.emplace(nd,v);
  };
  push(k,0);
  while(!q.empty()){
    int u = q.top().second;
    ll pd = q.top().first;
    q.pop();
    for(P p:g[u]) push(p.first,pd+p.second);
  }
  rep(i,m){
    int x,y;
    cin >> x >> y;
    --x; --y;
    cout << d[x]+d[y] << endl;
  }
}