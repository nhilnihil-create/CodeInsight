#include <bits/stdc++.h>
using namespace std;

/*
dreamとdreamerのように、前から読むと6番目まで違いが分からない(prefix)。
後ろから読めば早い段階で違いが分かるので、各stringをreverseして比較する。
*/

int main() {
  string s;
  cin >> s;
  vector<string> options = {"dream", "dreamer", "erase", "eraser"};
  
  reverse(s.begin(), s.end());
  for (int i = 0; i < 4; i++) reverse(options.at(i).begin(), options.at(i).end());
  
  bool divisible = true;
  for (int i = 0; i < (int)s.size();) {
    bool p_divisible = false;
    for (string c : options) {
      // sのi番目からc.size要素までがoptionsのどれかと一致したら、
      // フラッグを立てc.size文字分進める
      if (s.substr(i, c.size()) == c) {
        p_divisible = true;
        i += c.size();
      }
    }
    if (!p_divisible) {
      divisible = false;
      break;
    }
  }
 
  cout << (divisible ? "YES" : "NO") << endl;
}