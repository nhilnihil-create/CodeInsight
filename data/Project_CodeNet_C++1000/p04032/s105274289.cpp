#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  for(int i = 0; i < s.length() - 1; i++) {
    if(s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << "\n";
      return 0;
    }
    if(i < s.length() - 2) {
      if(s[i] == s[i + 2]) {
        cout << i + 1 << " " << i + 3 << "\n";
        return 0;
      }
    }
  }
  cout << "-1 -1"
       << "\n";
}