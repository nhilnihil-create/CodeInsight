#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  int N;
  while (cin >> N) {
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
      cin >> x[i];
    }
    int pre = 1, size = 1;
    ll res = 1;
    for (int i = 1; i < N; i++) {
      int cur = pre + 2;
      if (cur <= x[i]) {
        pre = cur;
        ++size;
        continue;
      }
      res = res * (size + 1) % MOD;
    }
    for (int i = 1; i <= size; i++) {
      res = res * i % MOD;
    }
    cout << res << endl;
  }
  return 0;
}
