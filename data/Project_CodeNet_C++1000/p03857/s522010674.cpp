//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
using P=pair<int,int>;
struct unionfind {
  vector<int> par;
  unionfind(int n) : par(n,-1) {}
  void init(int n) {par.assign(n,-1);}
  int find(int x) {
    if (par[x]<0) return x;
    else return par[x]=find(par[x]);
  }
  bool issame(int x,int y) {
    return find(x)==find(y);
  }
  bool unit(int x,int y) {
    x=find(x),y=find(y);
    if (x==y) return false;
    if (par[x]>par[y]) swap(x, y); 
    par[x]+=par[y];
    par[y]=x;
    return true;
  }
  int size(int x) {
    return -par[find(x)];
  }
};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,k,l,p,q,r,s;
  cin >> n >> k >> l;
  unionfind uf1(n),uf2(n);
  for(int i=0; i<k; i++) {
    cin >> p >> q;
    p--,q--;
    uf1.unit(p,q);
  }
  for(int i=0; i<l; i++) {
    cin >> r >> s;
    r--,s--;
    uf2.unit(r,s);
  }
  map<P,int> m;
  for(int i=0; i<n; i++) {
    m[P(uf1.find(i),uf2.find(i))]++;
  }
  for(int i=0; i<n; i++) {
    cout << m[P(uf1.find(i),uf2.find(i))] << " ";
  }
  cout << "\n";
}