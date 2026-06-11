#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  char next = a[0];
  int ca = 1, cb = 0, cc = 0;
  while (true) {
    if (next == 'a') {
      if (ca == a.size()) {
        cout << 'A' << endl;
        return 0;
      } else {
        next = a[ca];
        ca++;
      }
    } else if (next == 'b') {
      if (cb == b.size()) {
        cout << 'B' << endl;
        return 0;
      } else {
      	next = b[cb];
      	cb++;
      }
    } else {
      if (cc == c.size()) {
        cout << 'C' << endl;
        return 0;
      } else {
      	next = c[cc];
      	cc++;
      }
    }
  }
}