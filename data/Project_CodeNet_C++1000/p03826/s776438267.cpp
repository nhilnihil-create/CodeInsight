#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (a*b < x*y) {
    cout << x*y << endl;
  }
  if (a*b > x*y) {
    cout << a*b << endl;
  }
  if (a*b == x*y) {
    cout << a*b << endl;
  }
}