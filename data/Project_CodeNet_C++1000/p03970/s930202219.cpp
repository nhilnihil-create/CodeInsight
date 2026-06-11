#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s, t = "CODEFESTIVAL2016";
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) != t.at(i)) ans++;
  }
  
  cout << ans << '\n';
}