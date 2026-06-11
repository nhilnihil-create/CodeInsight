#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a <= c && b <= c) cout << a + b << endl;
  else if (a <= b && c <= b) cout << a + c << endl;
  else cout << b + c << endl;
}