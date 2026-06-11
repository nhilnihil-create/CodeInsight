#include <bits/stdc++.h>
using namespace std;

// recursionを用いた深さ優先探索

string s;
vector<string> options = {"dream", "dreamer", "erase", "eraser"};

bool DFS (int n) {
  if (n == s.size()) return true;  // 最後まで来た = 綺麗に分割できた
  
  for (string c: options) {
    if (s.substr(n, c.size()) == c && ((n + c.size()) <= s.size())) {
      if (DFS(n + c.size())) return true;  // nからc.size分進める
    }
  }
  
  return false; // 分割できませんでした
}

int main() {
  cin >> s;
  cout << (DFS(0) ? "YES" : "NO") << endl;
}