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
  ll N;
  cin >> N;
  ll ans = 1;
  for (int i = 1; i < 7; i++) {
    ll x = pow(2, i);
    if (x <= N) ans = x;
  }
  cout << ans << endl;
  return 0;
}