#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string ans;
  if (a > 0 && b > 0) {
    ans = "Positive";
  } else if ((a <= 0 && b >= 0) || (a >= 0 && b <= 0)) {
    ans = "Zero";
  } else if ((b % 2 - a % 2) % 2) {
    ans = "Positive";
  } else {
    ans = "Negative";
  }
  cout << ans << endl;
  return 0;
}
