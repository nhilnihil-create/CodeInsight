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
  string s;
  cin >> s;
  int ans = s.length();
  for (int i = 0; i < 26; i++) {
    if (s.find(('a' + i)) == string::npos) continue;
    string t(s.length(), '?');
    for (int j = 0; j < (int)s.length(); j++)
      if (s[j] == ('a' + i)) t[j] = s[j];
    int cnt = 0;
    while (t.find('?') != string::npos) {
      string t_(t.length() - 1, '?');
      for (int j = 0; j < (int)t_.length(); j++) {
        if (t[j] == ('a' + i) || t[j + 1] == ('a' + i)) {
          t_[j] = 'a' + i;
        }
      }
      t.swap(t_);
      cnt++;
    }
    // debug(t);
    // debug(cnt);
    ans = min(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}
