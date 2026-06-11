#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a * b * (a + b)) % 3 == 0) {
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}