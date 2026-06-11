#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  n -= 2;
  s = s.substr(0, n);
  while (1) {
    string t = s.substr(0, n / 2);
    t += t;
    if (s == t) {
      cout << n << endl;
      return 0;
    }
    n -= 2;
    s = s.substr(0, n);
  }
}