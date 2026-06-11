#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long X;
  cin >> X;
  int n = (-2 + ceil(sqrt(1 + 8 * X))) / 2 + 1;
  cout << n << endl;

  return 0;
}
