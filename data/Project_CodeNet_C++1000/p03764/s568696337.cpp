#include <iostream>
#include <vector>
using namespace std;

using int64 = long long;
const int64 kMod = 1000000007;

int64 Sum(const vector<int64>& x) {
  const int64 n = x.size();
  int64 ret = 0;
  int64 sum = 0;
  for (int64 i = 1; i < n; ++i) {
    sum += (x[i] - x[i - 1]) * i;
    ret += sum;
  }
  return ret % kMod;
}

int64 Solve(const vector<int64>& x, const vector<int64>& y) {
  return Sum(x) * Sum(y) % kMod;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int64> x(n), y(m);
  for (int i = 0; i < n; ++i)
    cin >> x[i];
  for (int i = 0; i < m; ++i)
    cin >> y[i];
  cout << Solve(x, y) << "\n";
  return 0;
}
