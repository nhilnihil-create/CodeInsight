#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  if (a == b && b == c) cout << 1 << endl;
  else if (a == b && b != c) cout << 2 << endl;
  else if (a != b && b == c) cout << 2 << endl;
  else if (a == c && c != b) cout << 2 << endl;
  else cout << 3 << endl;
}