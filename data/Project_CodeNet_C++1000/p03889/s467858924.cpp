/**
 *    author:  tourist
 *    created: 14.12.2019 10:28:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string t(s.rbegin(), s.rend());
  for (char& c : t) {
    if (c == 'b' || c == 'd') {
      c ^= 'b' ^ 'd';
    } else {
      c ^= 'p' ^ 'q';
    }
  }
  cout << (t == s ? "Yes" : "No") << '\n';
  return 0;
}
