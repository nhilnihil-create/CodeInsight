#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool n = false, w = false, s = false, e = false;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'N') n = true;
    else if (S.at(i) == 'W') w = true;
    else if (S.at(i) == 'S') s = true;
    else e = true;
  }
  if (((n && s) || (!(n) && !(s))) && ((w && e) || (!(w) && !(e)))) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}