#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

bool Solve() {
  int n;
  cin >> n;
  vector<int> xs(n);
  vector<int> v_count(n);
  int max_d = 0;
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    v_count[xs[i]]++;
    max_d = max(xs[i], max_d);
  }

  if (max_d % 2 == 1) {
    int k = (max_d + 1) / 2;
    if (v_count[k] != 2) return false;
    for (int x : xs) if (x < k) return false;
    for (int i = k + 1; i <= max_d; i++) {
      if (v_count[i] < 2) return false;
    }
    return true;
  } else {
    int k = max_d / 2;
    if (v_count[k] != 1) return false;
    for (int x : xs) if (x < k) return false;
    for (int i = k + 1; i <= max_d; i++) {
      if (v_count[i] < 2) return false;
    }
    return true;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  if (Solve()) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}