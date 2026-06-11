#include <bits/stdc++.h>
struct UnionFind {
public:
  int n;
  std::vector<int> par;
  UnionFind() {}
  UnionFind(int n): n(n) {
    par.resize(n, -1);
  }
  int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if(rx == ry) return;
    if(par[rx] < par[ry]) {
      std::swap(x, y);
      rx = root(x), ry = root(y);
    }
    par[rx] += par[ry];
    par[ry] = rx;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return -par[root(x)];
  }
};
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}
vi col;
map<int, bool> notnibu;
void sch(int now, int prev, int nowcol, const vvi &g, UnionFind &uf) {
  col[now] = nowcol;
  for(auto &nxt: g[now]) {
    if(nxt == prev) continue;
    if(col[nxt] == nowcol) {
      notnibu[uf.root(now)] = true;
      return;
    } else if(col[nxt] == -1) {
      sch(nxt, now, !nowcol, g, uf);
      if (notnibu[uf.root(now)]) return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll n, m; cin >> n >> m;
  vvi g(n);
  UnionFind uf(n);
  for(int i=0;i<(m);++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    uf.unite(a, b);
  }
  col.resize(n, -1);
  int id = 0;
  for(int i=0;i<(n);++i) {
    if(col[i] != -1) continue;
    sch(i, -1, 0, g, uf);
    id++;
  }
  ll a = 0, b = 0, c = 0;
  map<int, bool> one;
  for(int i=0;i<(n);++i) {
    if(uf.size(i) == 1) {
      one[uf.root(i)] = true;
      c++;
    }
  }
  vector<bool> sel(n);
  for(int i=0;i<(n);++i) {
    int e = uf.root(i);
    if(e == -1) continue;
    if(one[e] || sel[e]) continue;
    else if(notnibu[e]) b++;
    else a++;
    sel[e] = true;
  }
  cout << (a + b) * (a + b) + a * a + n * n - (n - c) * (n - c) << endl;
}
