#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
#define accum(x) accumulate((x).begin(), (x).end(), 0)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n, tot = 0;
  cin >> n;
  vector<int> v(n);
  rep(i, 0, n) {
    cin >> v[i];
    tot += v[i];
  }

  if (tot % 10 != 0) {
    cout << tot << endl;
    return 0;
  }

  sort(v.begin(), v.end());
  rep(i, 0, n) {
    int tmp = tot - v[i];
    if (tmp % 10 != 0) {
      cout << tmp << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
