#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

vector<int> g[100010];
int used[100010];

bool dfs(int now,int col){
    used[now]=col;
    for(auto nex:g[now]){
        if(used[nex]==0){
            if(dfs(nex,-col)==false) return false;
        }else if(used[nex]==used[now]) return false;
    }
    return true;
}

class DisjointSet{
public:
  vector<int> rank,p;
  vector<int> sz;
 
  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
    sz.resize(size,0);
    for(int i=0;i<size;i++) makeSet(i);
  }
 
  void makeSet(int x){
    p[x]=x;
    rank[x]=0;
    sz[x]=1;
  }
 
  bool same(int x,int y){
    return findSet(x)==findSet(y);
  }
 
  void unite(int x,int y){
    if(same(x,y)) return;
    link(findSet(x),findSet(y));
  }
 
  void link(int x,int y){
    if(rank[x]>rank[y]){
      p[y]=x;
      sz[x]+=sz[y];
    }else{
      p[x]=y;
      sz[y]+=sz[x];
      if(rank[x]==rank[y]){
        rank[y]++;
      }
    }
  }
 
  int findSet(int x){
    if(x!=p[x]){
      p[x]=findSet(p[x]);
    }
    return p[x];
  }
 
  int findSize(int x){
    return sz[findSet(x)];
  }
};

int main(){
  ll N,M;
  cin>>N>>M;

  DisjointSet us(N+1);
  rep(i,M){
      int a,b;
      cin>>a>>b;
      a--;b--;
      g[a].push_back(b);
      g[b].push_back(a);
      if(us.same(a,b));
      else us.unite(a,b);
  }

  ll ais=0;
  for(int i=0;i<N;i++) if(g[i].size()==0) ais++;

  ll com=0;
  ll ans=0;
  ll two=0;
  for(int i=0;i<N;i++){
      if(g[i].size()==0) continue;
      if(us.findSet(i)==i){
          com++;
          if(dfs(i,1)){
              ans+=2;
              two++;
          }else ans++;
      }
  }

  ans+=2*(two*(two-1));
  ans+=2*two*(com-two);
  ans+=(com-two)*(com-two-1);
  ans+=(N*N-(N-ais)*(N-ais));
  cout<<ans<<endl;



  return 0;
}
