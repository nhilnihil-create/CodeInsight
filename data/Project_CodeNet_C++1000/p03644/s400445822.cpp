#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N;
  cin >> N;
  vector<int> v = {64, 32, 16, 8, 4, 2, 1};
  for (auto x : v) {
    if (x <= N) {
      cout << x << endl;
      return 0;
    }
  }

  return 0;
}
