#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string res = "YES";
  for (int i = 0; i < s.size(); ++i) {
    string subS = s.substr(i, 5);
    if (subS == "dream") {
      i += 4;
      if (i + 3 < s.size() && s.substr(i + 1, 3) == "era") {
        continue;
      }
      if (i + 2 < s.size() && s.substr(i + 1, 2) == "er") {
        i += 2;
      }
    } else if (subS == "erase") {
      i += 4;
      if (i + 1 < s.size() && s.substr(i + 1, 1) == "r") {
        i++;
      }
    } else {
      res = "NO";
    }
  }

  cout << res << endl;
}
