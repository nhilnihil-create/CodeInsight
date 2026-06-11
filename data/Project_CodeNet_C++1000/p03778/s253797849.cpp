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
  ll W, a, b;
  cin >> W >> a >> b;
  ll ans = (a < b) ? b - (a + W) : a - (b + W);
  cout << max(ans, 0LL) << endl;
  return 0;
}