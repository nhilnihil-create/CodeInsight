#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<string> strs = {"dream", "dreamer", "erase", "eraser"};
  for (auto& str : strs) {
    reverse(str.begin(), str.end());
  }
  reverse(s.begin(), s.end());

  bool result = true;
  while (s.size() != 0) {
    bool match = false;
    for (auto str : strs) {
      if (equal(str.begin(), str.end(), s.begin())) {
        match = true;
        s = s.substr(str.size());
        break;
      }
    }
    if (!match) {
      result = false;
      break;
    }
  }

  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
