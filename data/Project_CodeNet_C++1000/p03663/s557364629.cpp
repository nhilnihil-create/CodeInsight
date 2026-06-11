#include <bits/stdc++.h>
using namespace std;
 
typedef long long lint;
 
void ans(lint n) {
  cout << "! " << n << endl;
}
 
bool q(lint n) {
  char c;
  cout << "? " << n << endl;
  cin >> c;
 
  return c == 'Y';
}
 
lint N;
bool debug(lint n) {
  cout << "? " << n << endl;
  return ((n <= N) == (to_string(n) <= to_string(N)));
}
 
int main() {
  int s;
  
  // cin >> N;
  // cin >> s;
 
  bool f = q(1000000000000);
  if (f) {
    s = 1;
    for (lint i = 9; !q(i); i = i * 10 + 9) s++;
  } else {
    s = 0;
    for (lint i = 1; q(i); i *= 10) s++;
  }
 
  lint l = pow(10, s - 1) - 1, r = pow(10, s) - 1;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    if (q(10 * m)) {
      r = m;
    } else {
      l = m;
    }
  }
 
  ans(r);
}