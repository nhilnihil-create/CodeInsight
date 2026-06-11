#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  int64_t X, t;
  cin >> X >> t;
  if (0 <= X - t) cout << X - t << endl;
  else cout << 0 << endl;
}