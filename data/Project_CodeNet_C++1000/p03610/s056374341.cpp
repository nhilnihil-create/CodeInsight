#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) if (i % 2 == 0) cout << s.at(i); cout << endl;
  return 0;
}
