#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<string> words = {"dream", "dreamer", "erase", "eraser"};

  reverse(s.begin(), s.end());
  rep(i, 4) reverse(words.at(i).begin(), words.at(i).end());

  bool canCreate = true;
  int start = 0;
  while (start < s.length()) {
    bool canDivide = false;
    for (int i = 0; i < 4; i++) {
      string word = words.at(i);
      if (s.substr(start, word.length()) == word) {
        start += word.length();
        canDivide = true;
        break;
      }
    }
    if (!canDivide) {
      canCreate = false;
      break;
    }
  }

  if (canCreate) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}