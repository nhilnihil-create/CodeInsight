#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int conx;
  int cony;
  if (x == 2) {
    conx = 2;
  }
  else if (x == 4 || x == 6 || x == 9 || x == 11) {
    conx = 1;
  }
  else {
    conx = 0;
  }
  if (y == 2) {
    cony = 2;
  }
  else if (y == 4 || y == 6 || y == 9 || y == 11) {
    cony = 1;
  }
  else {
    cony = 0;
  }
  if (conx == cony) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
