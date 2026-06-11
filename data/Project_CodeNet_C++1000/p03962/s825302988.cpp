#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(ALL(a));
  cout << unique(ALL(a)) - a.begin() << endl;
  return 0;
}
