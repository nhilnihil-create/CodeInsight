#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  
  if ((x > 0 && y > 0) || (x < 0 && y < 0)){
    if (x > y) cout << 2 + x - y << endl;
    else cout << y - x << endl;
  }
  if ((x > 0 && y < 0) || (x < 0 && y > 0)){
    cout << abs(y - (-x)) + 1 << endl;
  }
  if (x == 0 || y == 0){
    if (x > y) cout << x - y + 1 << endl;
    else cout << y - x << endl;
  }
}