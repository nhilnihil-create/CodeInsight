#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e10;
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x==y)return false;
        if(par[y]<par[x])swap(x,y);
        par[x]+=par[y];par[y]=x;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return -par[root(x)];
    }
    int root(int x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
};

signed main(){
  int n,k,l;
  cin>>n>>k>>l;

  UnionFind car(n);
  UnionFind train(n);

  rep(i,k){
    int p,q;
    cin>>p>>q;
    p--;q--;
    car.unite(p,q);
  }
  rep(i,l){
    int r,s;
    cin>>r>>s;
    r--;s--;
    train.unite(r,s);
  }
  map<pair<int,int>,int> m;
  rep(i,n){
      m[make_pair(car.root(i),train.root(i))]++;
  }
  rep(i,n){
    if(0<i)cout<<' ';
    cout<<m[make_pair(car.root(i),train.root(i))];
  }
  cout<<endl;

  return 0;
}
