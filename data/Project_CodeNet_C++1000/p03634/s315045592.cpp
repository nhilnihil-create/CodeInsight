#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  ll N; cin>>N;
  Graph G(N+1);
  rep(i,N-1){
    ll a,b,c; cin>>a>>b>>c;
    G.at(a).push_back(make_pair(b,c));
    G.at(b).push_back(make_pair(a,c));
  }
  ll Q,K; cin>>Q>>K;
  vector<ll> dist(N+1,-1);
  dist.at(K)=0;
  queue<ll> Que;
  Que.push(K);
  while(!Que.empty()){
    ll v = Que.front();
    Que.pop();
    for(auto p: G.at(v)){
      ll nv = p.first;
      ll cost = p.second;
      if(dist.at(nv)!=-1)continue;//訪問済み
      dist.at(nv) = dist.at(v)+cost;
      Que.push(nv);
    }
  }
  rep(i,Q){
    ll x,y; cin>>x>>y;
    cout<<dist.at(x)+dist.at(y)<<endl;
  }
}