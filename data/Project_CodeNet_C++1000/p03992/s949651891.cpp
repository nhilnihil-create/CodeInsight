#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i <s.size(); i++) {
    cout << s[i];
    if (i == 3) cout << " ";
  }
  cout << "\n";
  return 0;
}