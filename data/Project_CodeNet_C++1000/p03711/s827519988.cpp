#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

struct UnionFind{
  vector<int> par;
  UnionFind(int n) : par(n, -1){}
  int root(int x){ return (par[x] < 0) ? x : par[x] = root(par[x]); }
  int size(int x){ return -par[root(x)]; }
  bool issame(int x, int y){ return root(x) == root(y); }
  void marge(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return;
    if(x > y) swap(x, y);
    par[x] += par[y];
    par[y] = x;
  }
};

int main(void){
  int x, y;
  cin >> x >> y;
  UnionFind uf(13);
  int a[] = {1, 3, 5, 7, 8, 10, 12};
  int b[] = {4, 6, 9, 11};
  REP(i, 6) uf.marge(a[i], a[i+1]);
  REP(i, 3) uf.marge(b[i], b[i+1]);
  if(uf.issame(x, y)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}