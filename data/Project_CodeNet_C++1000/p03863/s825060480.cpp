#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  if (s[0] == s[(int)s.size() - 1]) {
    if (s.size() % 2 == 0) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  } else {
    if (s.size() % 2 == 0) {
      cout << "Second" << endl;
    } else {
      cout << "First" << endl;
    }
  }
  return 0;
}
