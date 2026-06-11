#include <bits/stdc++.h>
using namespace std;

// dpを使った場合
// こいつら↓をmainの外に出し、かつCの配列なら行けた

string options[4] = {"dream", "dreamer", "erase", "eraser"};
bool dp[100010];

int main() {
  string s;
  cin >> s;
  
  dp[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    if (!dp[i]) continue;
    for (string c : options) {
      // sのi番目からc.size要素までがoptionsのどれかと一致したら、
      // その末尾の添字に対応するdpの位置をtrueにする
      if (s.substr(i, c.size()) == c) dp[i + c.size()] = 1;
    }
  }
  
  // dp[s.size()](つまりsの末尾)がtrueということは、sがoptionsで綺麗に分割できたということ
  cout << (dp[s.size()] ? "YES" : "NO") << endl;
}
