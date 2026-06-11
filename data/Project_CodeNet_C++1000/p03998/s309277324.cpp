#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  unsigned int ca = 0, cb = 0, cc = 0;
  char turn = 'a';
  bool next = true;
  while (next) {
    switch (turn) {
      case 'a':
        if (ca == a.size()) {
          next = false;
          break;
        }
        turn = a[ca];
        ca++;
        break;
      case 'b':
        if (cb == b.size()) {
          next = false;
          break;
        }
        turn = b[cb];
        cb++;
        break;
      case 'c':
        if (cc == c.size()) {
          next = false;
          break;
        }
        turn = c[cc];
        cc++;
        break;
    }
  }

  cout << char(turn - 'a' + 'A') << endl;

  return 0;
}
