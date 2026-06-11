#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, x, y, z;
  x = 0;
  y = 0;
  z = 0;
  cin >> N;
  
  vector<int> btn(N);
  for (int i = 0; i < N; i++) {
  cin >> a;
  btn.at(i) = a;
  }
  
  for (int j = 0; j < N;) {
    if (btn.at(j) == 2) {
      x++;
      cout << x << endl;
      break;
    }
    else {
      y = btn.at(j) - 1;
      if (btn.at(y) == j + 1) {
      cout << -1 << endl;
      break;
      }
      else if (btn.at(y) != j + 1) {
      x++;
      z++;
      j = btn.at(j) - 1;
        if (z >= 100000) {
        cout << -1 << endl;
        break;
        }
      }
    }
  }
}