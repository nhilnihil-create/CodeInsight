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

const int MAX = 1e5 + 1;

int main() {
  int n, a;
  cin >> n;
  vector<int> A(MAX);
  double tot = 0;
  rep(i, 0, n) {
    cin >> a;
    A[a]++;
    A[a + 1]++;
    A[a + 2]++;
  }

  int ans = 0;
  rep(i, 0, MAX) ans = max(ans, A[i]);

  cout << ans << endl;

  return 0;
}
