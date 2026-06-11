#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  ll res = 0, mx = 0;
  for (int i = 0; i < N; i++) {
    ll A;
    cin >> A;
    if (i == 0) {
      res += A - 1;
      mx = 1;
      continue;
    }
    if (A <= mx + 1) {
      mx = max(mx, A);
    } else {
      res += (A - 1) / (mx + 1);
    }
  }
  cout << res << endl;
  return 0;
}
