#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int t;
  cin >> n >> t;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int max_value = 0;
  int max_gap = 0;
  for (int i = n - 1; i >= 0; i--) {
    UpdateMax(max_value, xs[i]);
    UpdateMax(max_gap, max_value - xs[i]);
  }

  int count = 0;

  max_value = 0;
  for (int i = n - 1; i >= 0; i--) {
    UpdateMax(max_value, xs[i]);
    if (max_gap == max_value - xs[i]) {
      count++;
    }
  }
  cout << count << endl;
}