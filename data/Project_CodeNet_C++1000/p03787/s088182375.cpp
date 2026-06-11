#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define long long long

class UnionFind {
public:
  vector<int> par, rank; // parent(negative := it's root and abs-value represents its size), depth
  UnionFind(int sz) : par(sz, -1), rank(sz, 0){}
  int find(int x){
    if(par[x]<0) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
    x=find(x); y=find(y);
    if(x==y) return;  // already belong to same tree
    if(rank[x] < rank[y]){  // y becomes parent node
      par[y] += par[x];
      par[x] = y;
    } else {  // x becomes parent node
      par[x] += par[y];
      par[y] = x;
      if(rank[x]==rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int size(int x){ return -par[find(x)]; }
}; // END class UnionFind

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> u(m),v(m);
  rep(i,m) cin>>u[i]>>v[i];

  UnionFind uf(2*n);
  rep(i,m) u[i]--,v[i]--;
  rep(i,m) uf.unite(u[i]+n, v[i]), uf.unite(u[i], v[i]+n);

  long alone=0;
  long bad=0;
  long good=0;
  set<int> checked;
  rep(i,n) if(checked.count(uf.find(i))==0){//dbg(i);
    if(uf.size(i)==1) alone++;
    else if(! uf.same(i, i+n)) good++;
    else bad++;
    checked.insert(uf.find(i));
    checked.insert(uf.find(i+n));
  }
//  dbg(alone),dbg(good),dbg(bad);

  long ans = alone*n*2L - alone*alone;
  ans += 2L*good*good;
  ans += bad*bad;
  ans += 2L*good*bad;

  cout << ans << endl;

  return 0;
}
