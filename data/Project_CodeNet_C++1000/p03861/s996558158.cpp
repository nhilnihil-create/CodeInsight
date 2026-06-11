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
  ll a, b, x;
  cin >> a >> b >> x;
  ll min_x_occ = a / x - (a % x == 0);
  ll max_x_occ = b / x;
  ll ans = max_x_occ - min_x_occ;
  cout << ans << endl;
  return 0;
}