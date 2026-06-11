#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;

  int even = 0;
  int odd = 0;
  rep(i, N) {
    int a;
    cin >> a;
    (a % 2 == 0 ? even : odd)++;
  }

  even += odd / 2;
  odd = odd % 2;

  cout << (even > 0 && odd > 0 ? "NO" : "YES") << endl;

  return 0;
}