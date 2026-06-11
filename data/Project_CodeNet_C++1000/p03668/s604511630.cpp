#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  vector<int> tree[N];
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  int grundy[N];
  function<int(int, int)> dfs = [&](int v, int p) {
    grundy[v] = 0;
    for (int u : tree[v])
      if (u != p) {
        grundy[v] ^= dfs(u, v) + 1;
      }
    return grundy[v];
  };
  cout << (dfs(0, -1) == 0 ? "Bob" : "Alice") << '\n';
  return 0;
}
