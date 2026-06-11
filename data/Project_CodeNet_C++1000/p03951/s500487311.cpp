#include <iostream>

using namespace std;

bool tst (int n, const string &s, const string &t, int pos) {
  for (int i = 0; i + pos < n; i++) {
    if (s[i + pos] != t[i]) return false;
  }
  return true;
}

int main () {
  int n;
  string s, t;
  cin >> n >> s >> t;

  for (int i = 0; i < n; i++) {
    if (tst(n, s, t, i)) {
      cout << n + i << '\n';
      return 0;
    }
  }
  cout << 2 * n << '\n';
}
