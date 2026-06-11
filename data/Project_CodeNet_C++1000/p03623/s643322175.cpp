#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if ((a - x) * (a - x) > (b - x) * (b - x)) {
    cout << 'B' << endl;
  }
  else {
    cout << 'A' << endl;
  }
}