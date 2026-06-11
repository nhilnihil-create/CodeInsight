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
  ll a, b, c;
  cin >> a >> b >> c;
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (a == b && b == c) {
    cout << -1 << endl;
    return 0;
  }
  bool flag = true;
  ll ans = 0;
  while (flag) {
    ll ha = a / 2, hb = b / 2, hc = c / 2;
    a = hb + hc;
    b = ha + hc;
    c = hb + ha;
    ans++;
    flag = (a % 2 == 0 && b % 2 == 0 && c % 2 == 0);
  }
  cout << ans << endl;
  return 0;
}