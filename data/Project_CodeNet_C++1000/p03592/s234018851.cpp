#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, k;
  cin >> x >> y >> k;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      int s = i*(y-j)+(x-i)*j;
      if (s == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}