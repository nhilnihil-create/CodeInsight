#include <iostream>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = a - b;
  int y = b * c;
  int z = x * d;
  if (a - b > 0) {
    cout << y + z;
  }
  else {
    cout << a * c;
  }
}