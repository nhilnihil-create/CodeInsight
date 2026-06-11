#include <bits/stdc++.h>
using namespace std;

// queueを用いた幅優先探索

int main() {
  string s;
  cin >> s;
  vector<string> options = {"dream", "dreamer", "erase", "eraser"};
  
  queue<int> BFS;  // index管理用queue
  BFS.push(0);
  
  bool divisible = false;
  while (!BFS.empty()) {
    int t = BFS.front();
    BFS.pop();
    
    if (t == s.size()) {  // 綺麗に分割できたとき
      divisible = true;
      break;
    }
    
    for (string c : options) {
      // sのi番目からc.size要素までがoptionsのどれかと一致したら、
      // 現在地からc.size文字分進めてqueueにpushする
      if (s.substr(t, c.size()) == c) {
        BFS.push(t + c.size());
      }
    }
  }
 
  cout << (divisible ? "YES" : "NO") << endl;
}