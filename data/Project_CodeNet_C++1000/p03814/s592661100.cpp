#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int hazime = 0, owari = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      hazime = i;
      break;
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'Z') {
      owari = i;
      break;
    }
  }
  cout << owari - hazime + 1;
}