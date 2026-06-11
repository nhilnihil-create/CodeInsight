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
  ll X, A, B;
  cin >> X >> A >> B;
  string ans;
  if (B - A <= 0) {
    ans = "delicious";
  } else if (B - A <= X) {
    ans = "safe";
  } else {
    ans = "dangerous";
  }
  cout << ans << endl;
  return 0;
}