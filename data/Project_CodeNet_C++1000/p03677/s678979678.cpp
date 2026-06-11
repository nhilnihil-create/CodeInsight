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

void add(vector<ll>& c1, vector<ll>& c0, int l, int r, int s) {
  if (l <= r) {
    c1[l] += 1;
    c1[r + 1] -= 1;
    c0[l] += s - l;
    c0[r + 1] -= s - l;
  }
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<ll> c1(m + 1, 0), c0(m + 1, 0);
    ll cost = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] < a[i + 1]) {
        cost += a[i + 1] - a[i];
        add(c1, c0, a[i] + 1, a[i + 1], 0);
      } else {
        cost += m + a[i + 1] - a[i];
        add(c1, c0, a[i] + 1, m - 1, 0);
        add(c1, c0, 0, a[i + 1], m - a[i] - 1);
      }
    }
    for (int i = 1; i < m; i++) {
      c1[i] += c1[i - 1];
      c0[i] += c0[i - 1];
    }
    ll mx = 0;
    for (int i = 0; i < m; i++) {
      mx = max(mx, c1[i] * i + c0[i]);
    }
    cout << cost - mx << endl;
  }
  return 0;
}
