#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int time_i = (a + b) >= 24 ? a + b - 24 : a + b;

  cout << time_i << "\n";
}
