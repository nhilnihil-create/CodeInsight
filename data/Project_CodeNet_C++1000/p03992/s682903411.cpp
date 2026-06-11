#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "";
  for (int i = 0; i < 4; i++) ans+= s[i];
  ans += " ";
  for (int i = 4; i < s.size(); i++) ans += s[i];

  cout << ans << endl;
}