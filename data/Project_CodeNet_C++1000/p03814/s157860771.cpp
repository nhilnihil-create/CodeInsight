#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int A = 0, Z = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A') {
      A = i;
      break;
    }
  }
  for (int i = s.size() - 1; i > A - 1; i--) {
    if (s.at(i) == 'Z') {
      Z = i;
      break;
    }
  }
  cout << Z - A + 1 << endl;
}