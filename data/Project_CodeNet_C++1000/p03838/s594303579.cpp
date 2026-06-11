#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int count(int x, int y) {
  if (x == y) {
    return 0;
  } else if (x < y) {
    return y - x;
  } else {  // x > y
    return x - y + 2;
  }
}

int main() {
  int x, y; cin >> x >> y;
  int cnt = count(x, y);
  cnt = min(cnt, count(-x, y) + 1);
  cnt = min(cnt, count(x, -y) + 1);
  cnt = min(cnt, count(-x, -y) + 2);

  cout << cnt << endl;
}
