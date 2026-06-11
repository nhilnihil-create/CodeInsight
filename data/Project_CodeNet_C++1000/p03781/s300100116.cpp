#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll X;
  while (cin >> X) {
    int res = 0;
    ll upper = 0;
    while (upper < X) {
      ++res;
      upper += res;
    }
    cout << res << endl;
  }
  return 0;
}
