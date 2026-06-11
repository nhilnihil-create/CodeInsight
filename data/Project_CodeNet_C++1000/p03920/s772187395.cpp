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

int main() {
  int N;
  while (cin >> N) {
    int k;
    for (int i = 1; i <= N; i++) {
      if (N - i <= 1ll * (i - 1) * i / 2) {
        k = i;
        break;
      }
    }
    vector<int> ans = {k};
    int rem = N - k;
    for (int i = k - 1; i >= 1; i--) {
      if (rem >= i) {
        ans.push_back(i);
        rem -= i;
      }
    }
    for (int x : ans) cout << x << endl;
  }
  return 0;
}
