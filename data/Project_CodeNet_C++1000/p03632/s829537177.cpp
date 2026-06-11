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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = 0;
  for (int i = 0; i <= 100; i++) {
    if (a <= i && c <= i && i <= b && i <= d) {
      ans++;
    }
  }
  cout << max(0LL, ans - 1) << endl;
  return 0;
}