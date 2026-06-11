#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

bool solve() {
  int N;
  cin >> N;
  int mini = INF, maxi = NINF;

  vector<int> v(N);

  for (int &a:v) {
    cin >> a;
    mini = min(a, mini);
    maxi = max(a, maxi);
  }

  if (maxi - mini > 1) {
    return false;
  }

  if (maxi == mini) {
    return maxi * 2 <= N || maxi == N-1;
  }

  int cnt = 0;
  for (int &a:v) {
    if (a == mini) {
      cnt++;
    }
  }

  if (maxi < cnt) {
    return false;
  }

  int kind = maxi - cnt;

  if (kind == 0) {
    return false;
  }

  return kind * 2 <= (N - cnt);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  if (solve()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
