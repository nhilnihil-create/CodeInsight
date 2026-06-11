#include <bits/stdc++.h>
using namespace std;

int simulate(string s, char c) {
  int ans = 0;
  while (s.length() > 0 && s != string(s.length(), c)) {
    string tmp = "";
    for (int i = 0; i < s.length() - 1; i++) {
      tmp += (s[i] == c || s[i + 1] == c ? c : s[i]);
    }
    s = tmp;
    ans++;
  }
  return ans;
}

int main(void) {
  string s;
  cin >> s;
  set<char> se;
  for (int i = 0; i < s.length(); i++) {
    se.insert(s[i]);
  }

  int ans = 10000;
  for (auto c : se) {
    ans = min(simulate(s, c), ans);
  }
  cout << ans << endl;
  return 0;
}