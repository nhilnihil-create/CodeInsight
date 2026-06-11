#include <bits/stdc++.h>
using namespace std;

string s, t = "CODEFESTIVAL2016";

int main() {
  cin >> s;
  int res = 0;
  for (int i = 0; i < s.size(); ++i) res += s[i] != t[i];
  cout << res << endl;
  return 0;
}
