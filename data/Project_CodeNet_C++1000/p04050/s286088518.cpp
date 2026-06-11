#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> xs(m);
  int odd_count = 0;
  for (int i = 0; i < m; i++) {
    cin >> xs[i];
    if (xs[i] % 2 == 1) {
      odd_count++;
    }
  }

  if (odd_count >= 3) {
    cout << "Impossible" << endl;
    return 0;
  }

  int processed_odd_count = 0;
  for (int i = 0; i < m; i++) {
    if (xs[i] % 2 == 1) {
      if (processed_odd_count == 0) {
        swap(xs[i], xs[0]);
      } else {
        swap(xs[i], xs[m - 1]);
      }
      processed_odd_count++;
      if (processed_odd_count == odd_count) break;
    }
  }

  for (int i = 0; i < m; i++) {
    cout << xs[i] << " ";
  }
  cout << endl;

  vector<int> ys;
  if (odd_count == 0) {
    if (xs[0] > 1) {
      ys.push_back(xs[0] - 1);
    }
    for (int i = 1; i < m; i++) {
      ys.push_back(xs[i]);
    }
    ys.push_back(1);
  } else if (odd_count == 1) {
    if (xs[0] > 1) {
      ys.push_back(xs[0] - 1);
    }
    for (int i = 1; i < m; i++) {
      ys.push_back(xs[i]);
    }
    ys.push_back(1);
  } else {
    if (xs[0] > 1) {
      ys.push_back(xs[0] - 1);
    }
    for (int i = 1; i < m - 1; i++) {
      ys.push_back(xs[i]);
    }
    ys.push_back(xs[m - 1] + 1);
  }

  cout << ys.size() << endl;
  for (int y : ys) {
    cout << y << " ";
  }
  cout << endl;
}