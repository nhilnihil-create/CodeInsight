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
  ll ans = 0;
  ll l, r;
  for (int i = 0; i < N; i++) {
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}