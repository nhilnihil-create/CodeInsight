#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n, b;
  cin >> n;
  vector<int> a(100002);
  rep(i, 0, n) {
    cin >> b;
    ++a[b];
    ++a[-~b];
    ++a[-~-~b];
  }
  cout << *max_element(a.begin(), a.end());
  return 0;
}