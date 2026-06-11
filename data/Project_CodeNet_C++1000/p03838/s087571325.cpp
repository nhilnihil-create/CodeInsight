#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long long x, y;
  cin >> x >> y;

  long long ret = 0;
  if (abs(x) > abs(y) && x > 0) {
    // flip sign
    ++ret;
    x *= -1;
    // increment
    ret += abs(x) - abs(y);
    x -= abs(x) - abs(y);
  } else if (abs(x) > abs(y) && x <= 0) {
    ret += abs(x) - abs(y);
    x += abs(x) - abs(y);
  } else if (abs(x) < abs(y) && x >= 0) {
    ret += abs(y) - abs(x);
    x += abs(y) - abs(x);
  } else if (abs(x) < abs(y) && x < 0) {
    // flip sign
    ++ret;
    x *= -1;
    // increment
    ret += abs(y) - abs(x);
    x += abs(y) - abs(x);
  }

  // flip sign
  if ((x > 0 && y < 0) || (x < 0 && y > 0))
    ++ret;

  cout << ret << endl;

  return 0;
}