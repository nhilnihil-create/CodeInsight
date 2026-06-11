#include <algorithm>
#include <iostream>
using namespace std;

int m(int x) { return x; }
template <typename... Ts>
int m(int x, Ts... xs) {
  return min(x, m(xs...));
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << m(a + b, b + c, c + a);
  return 0;
}