#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> alp(26, 0);
  bool ans = true;
  for (int i = 0; i < s.size(); i++) {
    if (alp.at(s.at(i) - 'a') != 0) {
      ans = false;
    }
    alp.at(s.at(i) - 'a')++;
  }
  if (ans) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
  return 0;
}
