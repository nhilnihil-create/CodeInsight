#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
struct edge{
  ll from,to,cost;
  edge(){}
  edge(ll f,ll t,ll c):from(f),to(t),cost(c){}
};

signed main(){

  int n,m;
  cin>>n>>m;
  vector<edge> edges(m);
  for(int i=0;i<m;++i){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    edges[i] = {a,b,-c};
  }

  constexpr ll inf = 1LL<<60;
  vector<ll> dist(n,inf);
  dist[0] = 0;
  auto chmin = [](auto& a,auto b){if(a>b){a=b;return true;}return false;};
  for(int i=0;i<n;++i)for(auto& e:edges){
    chmin(dist[e.to],dist[e.from]+e.cost);
  }
  //念のためもう一度
  for(int i=0;i<n;++i)for(auto& e:edges){
    chmin(dist[e.to],dist[e.from]+e.cost);
  }

  vector<int> negaloop(n,false);
  for(int i=0;i<n;++i)for(auto& e:edges){
    if(negaloop[e.from])negaloop[e.to]=1;
    if(chmin(dist[e.to],dist[e.from]+e.cost))negaloop[e.to]=negaloop[e.from]=1;
  }
  if(negaloop.back())cout<<"inf"<<endl;
  else cout<<-dist.back()<<endl;

}