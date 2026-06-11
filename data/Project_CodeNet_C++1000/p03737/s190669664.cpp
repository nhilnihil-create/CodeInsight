#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t, u;
  cin >> s >> t >> u;
  int S = (int)s.at(0), T = (int)t.at(0), U = (int)u.at(0);
  cout << (char)(S - 32) << (char)(T - 32) << (char)(U - 32) << endl;
}