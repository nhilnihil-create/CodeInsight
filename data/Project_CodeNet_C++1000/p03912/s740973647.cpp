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
  int N, M;
  cin >> N >> M;
  int X[N];
  for (int i = 0; i < N; i++) cin >> X[i];
  sort(X, X + N);
  int cnt[M], same[M];
  fill(cnt, cnt + M, 0);
  fill(same, same + M, 0);
  for (int i = 0; i < N; i++) {
    int j = i + 1;
    while (j < N && X[i] == X[j]) j++;
    cnt[X[i] % M] += j - i;
    same[X[i] % M] += (j - i) / 2;
    i = j - 1;
  }
  int ans = 0;
  for (int i = 1; 2 * i < M; i++) {
    int a = i, b = M - i;
    int sa = cnt[a], sb = cnt[b];
    if (sa > sb) swap(sa, sb), swap(a, b);
    ans += sa;
    ans += min((sb - sa) / 2, same[b]);
  }
  ans += cnt[0] / 2;
  if (M % 2 == 0) ans += cnt[M / 2] / 2;
  cout << ans << '\n';
  return 0;
}
