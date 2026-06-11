#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  a = abs(x - a);
  b = abs(x - b);
  cout << ((a < b) ? "A" : "B") << "\n";
}