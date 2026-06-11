#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;

bool used[101];

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int d = a;
  while (!used[d % b]) {
    if (d % b == c) {
      cout << "YES" << endl;
      return 0;
    }
    used[d % b] = true;
    d += a;
  }
  cout << "NO" << endl;
  return 0;
}
