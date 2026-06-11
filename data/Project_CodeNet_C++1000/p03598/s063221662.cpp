#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);

  int ans = 0;
  rep(i, n) {
    cin >> x[i];
    if (x[i] * 2 >= k) {
      ans += k - x[i];
    } else {
      ans += x[i];
    }
  }
  cout << 2 * ans;

  return 0;
}
