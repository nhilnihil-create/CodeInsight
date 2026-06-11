#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
using namespace std;

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

int N,K,L;

int main(){
  cin>>N>>K>>L;
  DisjointSet usk(N),usl(N);
  for(int i=0;i<K;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      if(usk.same(a,b));
      else usk.unite(a,b);
  }
  for(int i=0;i<L;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      if(usl.same(a,b));
      else usl.unite(a,b);
  }

  map<pair<int,int>,int> mp;
  for(int i=0;i<N;i++){
      int x=usk.findSet(i);
      int y=usl.findSet(i);
      mp[mkp(x,y)]++;
  }

  vector<int> ans(N,0);
  for(int i=0;i<N;i++){
      int x=usk.findSet(i);
      int y=usl.findSet(i);
      ans[i]=mp[mkp(x,y)];
  }

  for(int i=0;i<N;i++) cout<<ans[i]<<" ";
  cout<<endl;

  return 0;
}
