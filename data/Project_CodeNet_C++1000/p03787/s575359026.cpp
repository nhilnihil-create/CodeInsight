#include<bits/stdc++.h>
using namespace std;

#include<vector>

namespace Union_find {

  class union_find {
    int n;
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> _size;
  public:
    union_find(int _n);
    int find(int x);
    void unite(int x, int y);
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int i){int p=find(i);return _size[p];}
  };

  union_find::union_find(int _n) :n(_n), par(_n), rank(_n, 1),_size(_n,1) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  };

  int union_find::find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  void union_find::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]){
      _size[y]+=_size[x];
      par[x] = y;
    }
    else{
      _size[x]+=_size[y];
      par[y] = x;
    }
    if (rank[x] == rank[y])
      rank[x]++;

    return;
  }
}

using namespace Union_find;
int main(){
  int n,m;
  cin>>n>>m;
  union_find connect(n);
  union_find dual(n*2);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    connect.unite(u,v);
    dual.unite(u,v+n);
    dual.unite(v,u+n);
  }

  vector<int> checked(n,0);
  long long int iso=0;
  long long int duo=0;
  long long int non=0;
  for(int i=0;i<n;i++){
    int index=connect.find(i);
    if(checked[index]) continue;
    checked[index]=true;
    
    if(connect.size(index)==1) iso++;
    else if(dual.same(index,index+n)) non++;
    else duo++;
  }
  long long int res=iso*(n-iso)*2+iso*iso;
  res+=non*duo*2+non*non;
  res+=duo*duo*2;
  cout<<res<<endl;

}
