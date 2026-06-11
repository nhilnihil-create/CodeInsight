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
ll const MOD = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  ll ans = 1;
  for (int i = 1; i <= N; i++) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}