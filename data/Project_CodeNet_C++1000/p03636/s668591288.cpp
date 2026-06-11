#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int lastIndex = s.length() - 1;
  string replacementChar = std::to_string(s.length() - 2);
  string ans = s.replace(1, lastIndex - 1, replacementChar);

  cout << ans << endl;
}