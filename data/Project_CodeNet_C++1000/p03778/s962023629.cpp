#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int W, a, b; cin >> W >> a >> b;
  
  if (a + W < b) {
    cout << b - (a + W) << endl;
    return 0;
  }
  
  if (b + W < a) {
    cout << a - (b + W) << endl;
    return 0;
  }
  
  cout << 0 << endl;
  
}