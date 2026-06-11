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
ll min_r[9] = {1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};
ll max_r[9] = {399, 799, 1199, 1599, 1999, 2399, 2799, 3199, 4800};

int main() {
  ll N;
  cin >> N;
  ll a;
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    cin >> a;
    for (int i = 0; i < 9; i++) {
      if (min_r[i] <= a && a <= max_r[i]) m[i]++;
    }
  }
  ll ans = 0;
  for (auto p : m) {
    ans++;
  }
  ll max_ans;
  ll min_ans;
  if (m[8]) {
    ans--;
    min_ans = ans;
    max_ans = ans + m[8];
  } else {
    min_ans = ans;
    max_ans = ans;
  }
  cout << max(min_ans, 1LL) << " " << max_ans << endl;
  return 0;
}