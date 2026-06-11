#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "";
  for (int i = 0; i < s.length(); i += 2) {
    ans += s.at(i);
  }
  cout << ans << endl;
  return 0;
}