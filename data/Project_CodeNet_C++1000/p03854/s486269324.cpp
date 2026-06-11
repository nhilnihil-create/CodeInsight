#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  vector<string> cand = {"dreamer", "eraser", "dream", "erase"};
  cin >> s;
  reverse(s.begin(), s.end());
  rep(i, 4) reverse(cand[i].begin(), cand[i].end());

  bool flag = true;
  while (flag) {
    flag = false;
    // cerr << s << endl;
    rep(i, 4) {
      if (s.substr(0, cand[i].size()) == cand[i]) {
        s.erase(0, cand[i].size());
        flag = true;
        break;
      }
    }
  }
  cout << (s.size() == 0 ? "YES" : "NO") << endl;
  return 0;
}
