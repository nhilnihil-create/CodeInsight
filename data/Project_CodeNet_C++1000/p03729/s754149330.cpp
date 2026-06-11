#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t,u;
  cin >> s >> t >> u;
  char a,b,c,d;
  a = s.at(s.length()-1);
  b = t.at(0);
  c = t.at(t.length()-1);
  d = u.at(0);
  if (a == b && c == d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}