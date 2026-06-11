#include <iostream>

using namespace std;
int main() {
  int W, a, b;

  cin >> W >> a >> b;

  if (a + W < b) {
    cout << b - (a + W) << endl;
    return 0;
  }
  
  if (a > b + W) {
    cout << a - (b + W) << endl;
    return 0;
  }

  if (a + W > b) {
    cout << 0 << endl;
    return 0;
  }

  if (a < b + W) {
    cout << 0 << endl;
    return 0;
  }
  return 0;
}
