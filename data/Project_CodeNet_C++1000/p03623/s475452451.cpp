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
  ll x, a, b;
  cin >> x >> a >> b;
  ll dist = min(abs(x - a), abs(x - b));
  string ans = "B";
  if (dist == abs(x - a)) {
    ans = "A";
  }
  cout << ans << endl;
  return 0;
}