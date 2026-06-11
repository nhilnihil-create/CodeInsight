#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string words[4] = {"dream", "dreamer", "erase", "eraser"};
  string S;
  cin >> S;
  bool update = true;
  while (update) {
    update = false;
    for (int i = 0; i < 4; i++) {
      int n = words[i].length();
      if (S.length() < n) continue;
      string s = S.substr(S.length() - n, n);
      if (s == words[i]) {
        update = true;
        S = S.substr(0, S.length() - n);
      }
    }
  }
  cout << (S.length() == 0 ? "YES" : "NO") << '\n';
  return 0;
}
