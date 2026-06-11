#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << (abs(n - a) > abs(n - b) ? 'B' : 'A') << endl;
  return 0;
}
