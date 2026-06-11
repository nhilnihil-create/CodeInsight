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
  ll K, S;
  cin >> K >> S;
  int z;
  ll ans = 0;
  for (int x = 0; x <= S && x <= K; x++) {
    for (int y = 0; y <= S && y <= K; y++) {
      z = S - x - y;
      if (0 <= z && z <= K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}