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
    vector<int> a(N * N, -1);
    vector<pair<int, int>> events;
    for (int i = 1; i <= N; i++) {
      int x;
      cin >> x;
      --x;
      a[x] = i;
      events.emplace_back(x, i);
    }
    sort(events.begin(), events.end());
    bool ok = true;
    for (int i = 0, k = 0; i < N; i++) {
      int lim = events[i].first, val = events[i].second;
      int rem = val - 1;
      while (rem > 0 && k < lim) {
        if (a[k] == -1) {
          a[k] = val;
          --rem;
        }
        ++k;
      }
      if (rem > 0) {
        ok = false;
        break;
      }
    }
    for (int i = N - 1, k = N * N - 1; i >= 0; i--) {
      int lim = events[i].first, val = events[i].second;
      int rem = N - val;
      while (rem > 0 && k > lim) {
        if (a[k] == -1) {
          a[k] = val;
          --rem;
        }
        --k;
      }
      if (rem > 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      for (int x : a) {
        cout << x << " ";
      }
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
