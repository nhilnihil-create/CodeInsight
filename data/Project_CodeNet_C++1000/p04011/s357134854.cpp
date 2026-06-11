#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (b <= a) {
  cout << b*x+(a-b)*y << endl;
  }
  else {
    cout << a * x << endl;
  }
}
