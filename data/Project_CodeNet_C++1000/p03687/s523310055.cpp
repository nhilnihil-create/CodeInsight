#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  set<char> c_list;
  for (const char &c : S) {
    c_list.insert(c);
  }

  if (c_list.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1 << 29;

  for (const char &c : c_list) {
    int t_ans = 0;
    string t = S;
    string t_;
    while (true) {
      t_ = "";
      // cout << t << endl;
      ++t_ans;
      REP(i, t.length() - 1) {
        if (t.at(i) == c || t.at(i + 1) == c) {
          t_ += c;
        } else {
          t_ += t.at(i);
        }
      }

      if (all_of(t_.begin(), t_.end(), [c](char _c) { return _c == c; })) {
        break;
      }
      t = t_;
    }
    ans = min(ans, t_ans);
  }

  cout << ans << endl;

  return 0;
}
