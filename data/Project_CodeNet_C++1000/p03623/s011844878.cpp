#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  int diffA = abs(a - x);
  int diffB = abs(b - x);
  cout << (diffA < diffB? "A" : "B") << endl;
}