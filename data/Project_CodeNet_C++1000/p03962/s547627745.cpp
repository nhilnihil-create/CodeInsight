#include <iostream>
using namespace std;

int main() {
  int a, b, c, ans = 1;
  cin >> a >> b >> c;
  if (a == b) {
    if (b != c) ans = 2;
  } else {
    ans = 2;
    if (a != c && b != c) ans = 3;
  }
    
  cout << ans << endl;
}