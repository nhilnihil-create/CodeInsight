#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 100100100100100100;
struct edge{ll from;ll to;ll cost;};
edge G[2000];ll d[1000],V,E;
bool BellmanFord_reverse(ll s){//正の閉路が検出されたらtrue
  ll i,j;bool ne[V] = {};
  fill(d,d+V,-inf);d[s] = 0;
  for(i=0;i<V-1;i++){
    for(j=0;j<E;j++){
      if(d[G[j].from]!=-inf && d[G[j].to]<d[G[j].from]+G[j].cost){
        d[G[j].to] = d[G[j].from]+G[j].cost;
      }
    }
  }
  for(i=0;i<V;i++){
    for(j=0;j<E;j++){
      if(d[G[j].from]!=-inf && d[G[j].to]<d[G[j].from]+G[j].cost) ne[G[j].to] = true;
      if(ne[G[j].from]) ne[G[j].to] = true;
    }
  }
  return ne[V-1];
}
int main(){
  ll i;
  scanf("%lld%lld",&V,&E);
  for(i=0;i<E;i++){
    scanf("%lld%lld%lld",&G[i].from,&G[i].to,&G[i].cost);
    G[i].from--;G[i].to--;
  }
  if(BellmanFord_reverse(0)) printf("inf\n");
  else printf("%lld\n",d[V-1]);
}