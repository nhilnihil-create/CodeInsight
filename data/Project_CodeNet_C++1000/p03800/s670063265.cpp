#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, j, n) for (int i = (j); i < (n); i++)
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s.push_back(s[0]);
  vector<int> a(n + 2, 0);
  rep(i, 4) {
    a[0] = i &1, a[1] = (i>>1)&1;
    rep(j, n) { a[j + 2] = a[j] ^ a[j + 1] ^ (s[j + 1] == 'x'); }
 
    if (a[n] == a[0] && a[n + 1] == a[1]) {
      string t = "";
      rep(k, n) { t.push_back("SW"[a[k]]); }
      cout << t << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}