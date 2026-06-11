#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  set<char> st;
  rep(i, s.size()) st.insert(s[i]);
  int ans = 1001001001;
  for (auto c : st) {
    int l = 0, tmp = 0;
    rep(j, s.size()) {
      if (s[j] == c) {
        tmp = max(tmp, j - l);
        l = j + 1;
      }
    }
    tmp = max(tmp, (int)s.size() - l);
    // cerr << c << " " << tmp << endl;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
