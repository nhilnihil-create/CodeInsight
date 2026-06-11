#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int Max(const vector<int>& xs) {
  int value = INT32_MIN;
  for (int x : xs) value = max(x, value);
  return value;
}

int Min(const vector<int>& xs) {
  int value = INT32_MAX;
  for (int x : xs) value = min(x, value);
  return value;
}

bool Solve() {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  int max = Max(xs);
  int min = Min(xs);
  if (max - min >= 2) return false;

  if (max == min) {
    int x = max;
    return x == n - 1 || 2 * x <= n;
  } else {
    int c = max;
    int k = 0;
    for (int x : xs) if (x == c - 1) k++;
    return c - k >= 1 && 2 * (c - k) <= n - k;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  if (Solve()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}