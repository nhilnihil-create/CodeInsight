#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) { }
  void init(int n) { par.assign(n,-1); }

  int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y){
    return root(x) == root(y);
  }

  bool merge(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x){
    return -par[root(x)];
  }
};

int main(){
  int N,K,L;
  cin >> N >> K >> L;
  UnionFind uf1(N),uf2(N);
  for(int i=0; i<K; i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    uf1.merge(a,b);
  }
  for(int i=0; i<L; i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    uf2.merge(a,b);
  }
  map<P,int> mp;
  for(int i=0; i<N; i++){
    P p;
    p = make_pair(uf1.root(i),uf2.root(i));
    mp[p]++;
  }
  for(int i=0; i<N; i++){
    P p;
    p = make_pair(uf1.root(i),uf2.root(i));
    cout << mp[p];
    if(i != N-1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
  return 0;
}
