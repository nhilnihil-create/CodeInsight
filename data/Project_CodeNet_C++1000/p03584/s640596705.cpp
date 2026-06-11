#include <bits/stdc++.h>
using namespace std;
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
  int N, K;
  cin >> N >> K;
  int A[N];
  long long B[N];
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  long long ans = 0;
  for (int b = 30; b >= 0; b--)
    if ((K >> b) & 1) {
      long long tmp = 0;
      for (int i = 0; i < N; i++)
        if (A[i] < (1 << b)) tmp += B[i];
      ans = max(ans, tmp);
      for (int i = 0; i < N; i++)
        if ((A[i] >> b) & 1) A[i] ^= 1 << b;
    }
  long long tmp = 0;
  for (int i = 0; i < N; i++)
    if (A[i] <= 0) tmp += B[i];
  ans = max(ans, tmp);
  cout << ans << '\n';
  return 0;
}
