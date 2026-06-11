#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x, a, b, c, d;
  cin >> x >> a >> b;
  c=max((a-x),(x-a));
  d=max((b-x),(x-b));
  if (c>d) {
    cout << 'B' << endl;
  }
  else {
    cout << 'A' << endl;
  }
}
