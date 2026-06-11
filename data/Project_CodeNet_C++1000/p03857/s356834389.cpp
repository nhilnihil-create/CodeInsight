#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> parent;
  UnionFind(int n){
    parent.resize(n);
    for(int i=0;i<n;++i)parent[i]=i;
  }
  int find(int x){ return parent[x]==x?x:(parent[x]=find(parent[x]));}
  void unite(int x,int y){if(find(x)!=find(y))parent[find(y)]=find(x);}
  bool issame(int x,int y){return find(x)==find(y);}
};

using pi=pair<int,int>;
#define mp make_pair

int main(){
  int n,k,l;
  cin>>n>>k>>l;
  UnionFind Road(n),Rail(n);
  for(int i=0;i<k;++i){
    int p,q;
    cin>>p>>q;
    Road.unite(p-1,q-1);
  }
  for(int i=0;i<l;++i){
    int r,s;
    cin>>r>>s;
    Rail.unite(r-1,s-1);
  }
  map<pi,int> m;
  for(int i=0;i<n;++i) m[mp(Road.find(i),Rail.find(i))]++;
  for(int i=0;i<n;++i)cout<<m[mp(Road.find(i),Rail.find(i))]<<" ";
}