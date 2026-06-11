#include <bits/stdc++.h>
using namespace std;
int main() {
  int W, a, b;
  cin >> W >> a >> b;
  int c = a - b;
  if (c < 0) {c *= -1;}
  if (c <= W) {cout << 0 << endl;}
  else {cout << c - W << endl;}
}