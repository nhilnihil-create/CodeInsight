#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> c(26);
  rep (i, s.length()) c.at(s.at(i) - 'a')++;

  int num = -1;
  char ans;
  for (int i = 0; i <= 25; i++) {
    if (c.at(i) == 0) {
      num = i;
      ans = i + 'a';
      break;
    }
  }

  if (num == -1) {
    cout << "None" << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}