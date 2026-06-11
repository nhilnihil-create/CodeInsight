#include <iostream>
using namespace std;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  cout << x * min(n, k) + y * max(n-k, 0) << endl;
}