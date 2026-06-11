#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans = INF;
  if (y - x > 0) ans = min(ans, y - x);
  if (y - (-x) >= 0) ans = min(ans, y - (-x) + 1);
  if (-y - x >= 0) ans = min(ans, -y - x + 1);
  if (-y - (-x) >= 0) ans = min(ans, -y - (-x) + 2);
  cout << ans << endl;
  return 0;
}