#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;

  cin >> N;

  int64_t x = 1;
  while (x <= N) {
    x *= 2;
  }
  cout << x / 2;

  return 0;
}
