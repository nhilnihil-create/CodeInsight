#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ll X, Y;
  cin >> X >> Y;
  bool res = abs(X - Y) >= 2;
  cout << (res ? "Alice" : "Brown") << endl;
  return 0;
}
