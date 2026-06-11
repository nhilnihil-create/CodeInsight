#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  
  
  if (b > a + W) {
    cout << b - (a + W) << endl;
  } else if (b + W < a) {
    cout << a - (b + W) << endl;
  } else {
    cout << 0 << endl;
  }
  
}