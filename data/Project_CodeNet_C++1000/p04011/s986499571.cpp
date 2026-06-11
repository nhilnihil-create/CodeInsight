#include <iostream>
using namespace std;

int main() {
  int n, k, x, y, ret;
  cin >> n;
  cin >> k;
  cin >> x;
  cin >> y;
  if (n > k) {
    ret = k * x + (n - k) * y;
  } else {
    ret = n * x;
  }
  cout << ret << endl;
  return 0;
}