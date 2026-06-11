#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int words_size = 4;
  vector<string> words = {"dreamer", "dream", "eraser", "erase"};

  // 左右反転
  reverse(S.begin(), S.end());
  for (int i = 0; i < words_size; i++) {
    reverse(words[i].begin(), words[i].end());
  }

  bool match = false;
  for (int i = 0; i < S.size();) {
    match = false;
    for (int j = 0; j < words_size; j++) {
      string word = words[j];
      if (S.substr(i, word.size()) == word) {
        match = true;
        i += word.size();
      }
    }

    if (match == false || i == S.size()) {
      break;
    }
  }

  cout << (match ? "YES" : "NO") << endl;
  return 0;
}