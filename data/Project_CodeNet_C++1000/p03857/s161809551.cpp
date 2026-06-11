#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> G;
vector<bool> seen;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar(ll n, ll set){
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=set;
      mkpar(next_n,set);
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

void dfs(){
  
}
//どちらでも、いみわかった
//1は自分の都市自身だけか
//道路の関係いれたあと、線路でも満たしているか
//しゃくとり？TLEになんないかな
//1個にいれて2個はいってるか、かな
//2 3
//2 5と
//3 5で35判定か
//むずいな。unionfindするかどうか
//道路の3と5の親が一致して、かつ線路の3と5の親が一致してるか
//N^2/2すべての組み合わせで探索になると無理か
//KとLの組み合わせだけしらべりゃいいのか
//いけるけどやだな、、がんばるか。22:01
//いけた。22:12
//sample以外全部WAかい
//連結されているもの同士か。どう勘定するか。sizeか
//鉄道の連結が、道路で満たしてなければいれない、
//tree2のサイズが答えになる、かな
//なおした22:36 全部WAか
//ああ、
//2 5と
//2 3
//3 5
//があったら2 5は加算されるべきだが排除されているということだね
//DFSしてるんならつどissame判定もいけるじゃろか
//それだと、2-3 2-5のときに3-5の判定がいけないのか
//parが同じもので重複してるものを探す必要があるか
//tree1.par[1]のものが{1,2,3,4}
//tree2.par[1]のものが{1,2,4,5,6}とかだったら1,2,4は3になる
//{1,2,3}
//{2,3,5}とかだと詰むや
//{1,2,3,4}
//{1,2}{3,4}の場合
//tree1.par[1]=1
//tree1.par[2]=1
//tree1.par[3]=1
//tree1.par[4]=1
//tree1.par[5]=2
//tree1.par[6]=2
//...
//tree1.par[N]=N

//tree2.par[1]=1
//tree2.par[2]=2
//tree2.par[3]=3
//tree2.par[4]=3
//tree2.par[5]=2
//tree2.par[6]=2

//のとき5-6と3-4がペアになるべき
//(1,3)=3,4 (2,2)=5,6みたいな？
//multimapにいれるかんじ。サイズが2になったときにメモしとく
//AC増えたけどTLE6個だな
//mapに重複数だけメモしといて、mapのペアを出力させりゃいいかな
int main(){
  ll N,K,L; cin>>N>>K>>L;
  G.assign(N+1, vector<ll>(0,0));
  map<pair<ll,ll>,ll> mp;
  seen.assign(N+1, false);
  UnionFind tree1(N), tree2(N);
  for(int i=0; i<K; i++){
    ll p,q; cin>>p>>q;
    G[p].emplace_back(q);
    G[q].emplace_back(p);
  }
  for(int i=1; i<=N; i++){    
    tree1.mkpar(i,i);
  }
  G.assign(N+1, vector<ll>(0,0));
  for(int i=0; i<L; i++){
    ll p,q; cin>>p>>q;
    G[p].emplace_back(q);
    G[q].emplace_back(p);
  }
  seen.assign(N+1, false);
  for(int i=1; i<=N; i++)
    tree2.mkpar(i,i);
  //mapに入れる。カウントが2だったら保存しとく。これすごい重い
  for(ll i=1; i<=N; i++){
    ll t1=tree1.par[i], t2=tree2.par[i];
    mp[make_pair(t1,t2)]++;
  }
  for(int i=1; i<=N; i++){
    ll t1=tree1.par[i], t2=tree2.par[i];
    cout<<mp[make_pair(t1,t2)];
    if(i<N) cout<<" ";
  }
}
