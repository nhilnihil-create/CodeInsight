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

template<class T> vector<T> CumulativeSumVector(const vector<T>& xs) {
  int n = xs.size();
  vector<T> c_sums(n + 1);
  for (int i = 0; i < n; i++) {
    c_sums[i + 1] = c_sums[i] + xs[i];
  }
  return c_sums;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int64> xs;
  vector<char> ops;
  ops.push_back('+');
  for (int i = 0; i < 2 * n - 1; i++) {
    if (i % 2 == 0) {
      int64 x;
      cin >> x;
      xs.push_back(x);
    } else {
      char op;
      cin >> op;
      ops.push_back(op);
    }
  }

  vector<int64> c_sums = CumulativeSumVector(xs);

  int64 ans = INT64_MIN;
  int64 current = 0;
  for (int i = 0; i < n; i++) {
    if (ops[i] == '-') {
      int p = n;
      for (int j = i + 1; j < n; j++) {
        if (ops[j] == '-') {
          p = j;
          break;
        }
      }
      int64 s = current - (c_sums[p] - c_sums[i]) + (c_sums[n] - c_sums[p]);
      UpdateMax(ans, s);
    }

    if (ops[i] == '+') current += xs[i];
    else if (ops[i] == '-') current -= xs[i];
  }
  UpdateMax(ans, current);

  cout << ans << endl;
}