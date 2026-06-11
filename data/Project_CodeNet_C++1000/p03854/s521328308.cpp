#include <bits/stdc++.h>
using namespace std;

signed main() {
  string s;
  cin >> s;
  int i = 0;
  while (i + 5 <= int(s.size())) {
    if (!(s[i] == 'd' || s[i] == 'e')) {
      cout << "NO\n";
      return 0;
    }
    else if (s[i] == 'd') {
      if (s.substr(i, 5) != "dream") {
        cout << "NO\n";
        return 0;
      }
      else if (i + 7 <= int(s.size())) {
        if (s[i + 5] == 'e' && s[i + 6] == 'r') {
          if (i + 8 <= int(s.size()) && s[i + 7] == 'a') 
            i += 5;
          else if (i + 7 <= int(s.size()))
            i += 7;
          else
            i += 5;
        }
        else
          i += 5;
      }
      else 
        i += 5;
    }
    else {
      if (s.substr(i, 5) != "erase") {
        cout << "NO\n";
        return 0;
      }
      else if (i + 6 <= int(s.size())) {
        if (s[i + 5] == 'r') {
          if (i + 7 <= int(s.size()) && s[i + 6] == 'a') 
            i += 5;
          else if (i + 6 <= int(s.size()))
            i += 6;
          else
            i += 5;
        }
        else
          i += 5;
      }
      else 
        i += 5;
    }
  }
  if (int(s.size()) == i)
    cout << "YES\n";
  else
    cout << "NO\n";
}