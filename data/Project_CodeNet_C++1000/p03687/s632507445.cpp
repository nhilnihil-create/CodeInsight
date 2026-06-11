#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;

  int ans = 1e9;
  rep(si, s.size()) {
    string t = s;
    while (true) {
      bool same = true;
      rep(ti, t.size()) {
        if (t[ti] != s[si]) same = false;
      }
      if (same) break;
      string tp = "";
      rep(ti, t.size() - 1) {
        if (t[ti] == s[si]) tp += t[ti];
        else tp += t[ti + 1];
      }
      t = tp;
    }
    ans = min(ans, (int)(s.size() - t.size()));
  }
  cout << ans << endl;
  return 0;
}