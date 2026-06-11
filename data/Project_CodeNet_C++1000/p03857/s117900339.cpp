#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (int i = a; i < (int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { \
    return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
template<typename T> bool chmin(T &a, const T &b) {if (a > b) { a = b; return true; }return false;}
template<typename T> bool chmax(T &a, const T &b) {if (a < b) { a = b; return true; }return false;}

using ll = int_fast64_t;
using PII = pair<int, int>;

constexpr ll INF = (1e9);
constexpr ll MOD = (1e9+7);

struct UnionFind {
  vector<int> data;
  UnionFind(int n) : data(n, -1) {}
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
  int n, k, l; cin >> n >> k >> l;
  UnionFind UF1(n);
  UnionFind UF2(n);
  REP(i,k) {
    int p, q; cin >> p >> q;
    p--; q--;
    UF1.merge(p, q);
  }
  REP(i,l) {
    int r, s; cin >> r >> s;
    r--; s--;
    UF2.merge(r, s);
  }
  map<PII, int> mp;
  REP(i,n) mp[make_pair(UF1.root(i), UF2.root(i))]++;
  REP(i,n) {
    cout << mp[make_pair(UF1.root(i), UF2.root(i))] << " ";
  }
  cout << endl;
  return 0;
}
