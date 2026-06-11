#include <bits/stdc++.h>
using namespace std;

// stackを用いた深さ優先探索

int main() {
  string s;
  cin >> s;
  vector<string> options = {"dream", "dreamer", "erase", "eraser"};
  
  stack<int> DFS;  // index管理用stack
  DFS.push(0);
  
  bool divisible = false;
  while (!DFS.empty()) {
    int t = DFS.top();
    DFS.pop();
    
    if (t == s.size()) {  // 綺麗に分割できたとき
      divisible = true;
      break;
    }
    
    for (string c : options) {
      // sのi番目からc.size要素までがoptionsのどれかと一致したら、
      // 現在地からc.size文字分進めてstackにpushする
      if (s.substr(t, c.size()) == c) {
        DFS.push(t + c.size());
      }
    }
  }
 
  cout << (divisible ? "YES" : "NO") << endl;
}