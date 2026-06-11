#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  if (s.size() >= 4) {
    if (s.substr(0, 4) == "YAKI") {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
