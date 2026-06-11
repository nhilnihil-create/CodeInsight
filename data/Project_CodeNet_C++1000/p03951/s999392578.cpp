#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  int ans;
  bool sum = true;
  if (s.size() <= t.size()) {
    for (int i = 0; i < s.size(); i++) {
      string st = s.substr(0, i) + t;
      if (st.substr(0, s.size()) == s && st.substr(st.size() - t.size()) == t) {
        ans = st.size();
        sum = false;
        break;
      }
    }
    if (sum) {
      ans = s.size() + t.size();
    }
  } else {
    for (int i = 0; i < t.size(); i++) {
      string st = s + t.substr(t.size() - i);
      if (st.substr(0, s.size()) == s && st.substr(st.size() - t.size()) == t) {
        ans = st.size();
        sum = false;
        break;
      }
    }
    if (sum) {
      ans = s.size() + t.size();
    }
  }

  cout << ans << endl;
}