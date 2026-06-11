#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pref(string &s, string &sw, int n) {
  if ((int)s.size() - n < (int)sw.size()) {
    return 0;
  }
  
  for (int i = 0; i < sw.size(); i++) {
    if (s[i + n] != sw[i]) return 0;
  }
  return 1;
}

int main() {
  
  string tc[] = {"remaerd", "resare", "maerd", "esare"};
  
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int p = 0;
  while (p < s.size()) {
    int found = 0;
    for (int i = 0; i < 4; i++) {
      if (pref(s, tc[i], p)) {
        p += tc[i].size();
        found = 1;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
      return 0;
    }
  }
  if (p == s.size())
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
