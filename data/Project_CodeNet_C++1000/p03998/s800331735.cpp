#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int A(a.length()), B(b.length()), C(c.length());
  int ia(0), ib(0), ic(0);
  a += ".";
  b += ".";
  c += ".";

  char t = 'a';
  while (ia <= A && ib <= B && ic <= C) {
    if (t == 'a') {
      t = a[ia++];
    } else if (t == 'b') {
      t = b[ib++];
    } else if (t == 'c') {
      t = c[ic++];
    }
  }

  char ans;
  if (ia > A) ans = 'A';
  if (ib > B) ans = 'B';
  if (ic > C) ans = 'C';
  cout << ans << endl;
}
