#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int mx = 0;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'I') {
      x++;
    }
    if (s.at(i) == 'D') {
      x--;
    }
    mx = max(mx, x);
  }
  cout << mx << endl;
  return 0;
}
