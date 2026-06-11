#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t, u;
  cin >> s >> t >> u;
  s.at(0) = toupper(s.at(0));
  t.at(0) = toupper(t.at(0));
  u.at(0) = toupper(u.at(0));

  cout << s.at(0) << t.at(0)<< u.at(0) << endl;
}
