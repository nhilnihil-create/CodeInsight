#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  //木の根なら-(size of tree) それ以外は木の根のindexが入っている。      
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
  int n,k,l;
  cin >> n >> k >> l;
  UnionFind t(n);
  UnionFind a(n);
  int p[k],q[k];
  rep(i,k){
    cin >> p[i] >> q[i];
    p[i]--;q[i]--;
    t.unite(p[i],q[i]);
  }
  int r[l],s[l];
  rep(i,l){
    cin >> r[i] >> s[i];
    r[i]--;s[i]--;
    a.unite(r[i],s[i]);
  }
  vector<tuple<int, int, int> > g;
  rep(i,n){
    g.pb(make_tuple(t.root(i), a.root(i), i));
    //        cout << t.root(i) << " " << a.root(i) << endl;
  }
  int ans[n];
  sort(g.begin(),g.end());
  int c=1;
  rep(i,n-1){
    int tr=get<0>(g[i]);
    int ai=get<1>(g[i]);
    int ntr=get<0>(g[i+1]);
    int	nai=get<1>(g[i+1]);
    if(tr==ntr && ai==nai){
      c++;
      if(i==n-2){
	rep(j,c){
	  int ind=get<2>(g[i+1-j]);
	  ans[ind]=c;
	}
      }
    }
    else{
      rep(j,c){
	int ind=get<2>(g[i-j]);
	ans[ind]=c;
      }
      c=1;
      if(i==n-2){
	int ind=get<2>(g[i+1]);
	ans[ind]=c;
      }
    }
  }
  rep(i,n){
    cout << ans[i] << endl;
  }


  return 0;
    

}
