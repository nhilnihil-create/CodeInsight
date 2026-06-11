#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//1-2-3-4-5
//b-2-3-4-w
//b-b-b-w-w b
  
//1-Nの最短距離をお互いとりあう
//くっついたときに、お互いの陣地をカウント
//DFSでサイズ測れそう
//1からNまでDFSで、Nにいたったら深さをおさえておく
//Nまでの経路を知りたい･･･どうしよう
//1個前の親を記録しておくか
//1が根
//1-2-3-N //2マスうめ、wは3から2以外の方向へのサイズ、 bは2から3以外の方向へのサイズ
//1-2-3-4-N// 3マスうめ w4 b3
//1-2-3-4-5-N // 4 w3 b4vector<vector<ll>> G;
//
vector<bool> seen;
vector<vector<ll>> G;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar(ll n){
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=n;
      mkpar(next_n);
    }
  }
  
  ll root(ll x){
    if(par[x]==x)
      return x;
    return par[x]=root(par[x]);
  }
  
  void unite(ll x, ll y){
    ll rx=root(x), ry=root(y);
    if(rx==ry)
      return;
    par[ry]=rx;
    siz[rx]+=siz[ry];    
  }
  
  bool issame(ll x, ll y){
    return root(x)==root(y);
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
};

void dfs(ll n){
  for(auto next_n:G[n]){
    if(seen[next_n]) continue;
    seen[next_n]=true;
    dfs(next_n);
  }
}

int main(){
  ll N; cin>>N;
  ll wsize=-1,bsize=-1;
  G.assign(N+1, vector<ll>());
  seen.assign(N+1,false);
  for(int i=0; i<N-1; i++){
    ll a,b; cin>>a>>b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  UnionFind tree(N);
  seen[1]=true;
  tree.mkpar(1);
  ll cnt=-1, n=N;
  while(n!=1){
    n=tree.par[n];
    cnt++;
  }
  n=N;
  ll wpos=cnt/2;
  while(wpos>0){
    n=tree.par[n];
    wpos--;
  }
  ll w=n,b=tree.par[n];
  seen.assign(N+1,false); seen[b]=true; dfs(w);
  for(int i=1; i<=N; i++) if(seen[i]) wsize++;
  seen.assign(N+1,false); seen[w]=true; dfs(b);
  for(int i=1; i<=N; i++) if(seen[i]) bsize++;
  //3 2=F
  //2 2=S
  //3 4=S
  if(bsize>wsize) cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
}