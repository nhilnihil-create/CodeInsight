#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  bool c=false, d=false, e=false;
  cin >> x >> y;
  c = x%3, d = y%3, e = (x+y)%3;
  cout << (c*d*e == 0 ? "Possible" : "Impossible") << endl;
}