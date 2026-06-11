#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  string ans;
  
  for (int i = 0; i < s.length(); i++) {
    if (i%2 == 0)
      ans += s[i];
  }
  
  cout << ans;
}