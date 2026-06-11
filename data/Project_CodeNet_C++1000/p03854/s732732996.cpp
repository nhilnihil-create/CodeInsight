#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> v;
  v.push_back("dream");
  v.push_back("dreamer");
  v.push_back("erase");
  v.push_back("eraser");

  bool dp[s.size() + 1];
  for (int i = 0; i < s.size() + 1; i++) {
    dp[i] = false;
  }
  dp[0] = true;
  for (int i = 0; i < s.size() + 1; i++) {
    if (!dp[i]) {
      continue;
    }
    for (int j = 0; j < v.size(); j++) {
      if (s.substr(i, v[j].size()) == v[j]) {
        dp[i + v[j].size()] = true;
        // cout << i + v[j].size() << endl;
      }
    }
  }
  if (dp[s.size()]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
