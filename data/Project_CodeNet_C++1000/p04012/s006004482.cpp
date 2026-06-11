#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (char c = 97; c <= 122; c++) {
    if (count(s.begin(), s.end(), c) % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}