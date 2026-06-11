#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  struct UnionFind{
    int n;
    vector<int> r,p;
    UnionFind(){}
    UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
    int find(int x){
      return (x==p[x]?x:p[x]=find(p[x]));
    }
    bool same(int x,int y){
      return find(x)==find(y);
    }
    void unite(int x,int y){
      x=find(x);y=find(y);
      if(x==y) return;
      if(r[x]<r[y]) swap(x,y);
      r[x]+=r[y];
      p[y]=x;
    }
  };
  int N,K,L;
  cin>>N>>K>>L;
  UnionFind ro(N),li(N);
  for(int i=0;i<K;i++){
    int p,q;
    cin>>p>>q;
    p--;q--;
    ro.unite(p,q);
  }
  for(int i=0;i<L;i++){
    int p,q;
    cin>>p>>q;
    p--;q--;
    li.unite(p,q);
  }
  std::vector<int> v(N);
  for(int i=0;i<N;i++)v[i]=ro.find(i)*1000000+li.find(i);
  sort(v.begin(),v.end());
  for(int i=0;i<N;i++){
    int l=0;
    int r=N-1;
    int m=(l+r)/2;
    while(v[m]!=ro.find(i)*1000000+li.find(i)){
      if(v[m]<ro.find(i)*1000000+li.find(i))l=m+1;
      else r=m-1;
      m=(l+r)/2;
    }
    int ans=1;
    for(int i=m-1;v[i]==v[m]&&i>=0;i--)ans++;
    for(int i=m+1;v[i]==v[m]&&i<N;i++)ans++;
    cout<<ans<<" ";
  }
  cout<<endl;
}
