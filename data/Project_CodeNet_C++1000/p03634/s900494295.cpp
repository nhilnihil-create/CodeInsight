#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{ll to, cost;};


int main(){
  ll n, i, a, b, c, q, k,x,y, f;
  scanf("%lld", &n);
  vector<edge> V[n];
  ll d[n] = {};
  for(i=0; i<n-1;i++){
    scanf("%lld%lld%lld", &a, &b, &c);a--;b--;
    V[a].push_back(edge{b, c});
    V[b].push_back(edge{a, c});
  }
  scanf("%lld%lld", &q, &k);
  k--;
  queue<ll> Q;
  Q.push(k);
  while(!Q.empty()){
    f = Q.front();
    Q.pop();
    for(i=0;i<V[f].size();i++){
      if(d[V[f][i].to] == 0){
        d[V[f][i].to] = d[f] + V[f][i].cost;
        Q.push(V[f][i].to);
      }
    }
  }
  for(i=0;i<q;i++){
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    printf("%lld\n", d[x]+d[y]);
  }
}
