#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  vector<int> x[26];
  for (int i = 0; i < 26; i++) x[i].emplace_back(0);
  for (int i = 0; i < s.size(); i++) x[s.at(i) - 'a'].emplace_back(i + 1);
  for (int i = 0; i < 26; i++) x[i].emplace_back(s.size() + 1);
  
  int ans = 100;
  for (int i = 0; i < 26; i++) {
    int keep = 0;
    for (int j = 1; j < x[i].size(); j++) {
      keep = max(keep, x[i].at(j) - x[i].at(j - 1) - 1);
    }
    ans = min(ans, keep);
  }
  
  cout << ans << '\n';
}