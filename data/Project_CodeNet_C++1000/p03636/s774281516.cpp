#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  cout << s.at(0) << s.size() - 2 << s.at(s.size() - 1) << endl;
  return 0;
}
