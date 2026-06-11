#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
  cin >> n >> s >> t;
  for (int i = n; i >= 0; --i) {
    if (s.substr(n - i, i) == t.substr(0, i)) {
      cout << 2 * n - i << endl;
      break;
    }
  }
  return 0;
}